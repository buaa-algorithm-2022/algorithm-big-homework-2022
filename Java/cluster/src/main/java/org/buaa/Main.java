package org.buaa;

import io.netty.channel.ChannelInboundHandlerAdapter;
import org.buaa.algorithm.AlgoClientHandler;
import org.buaa.algorithm.AlgoServerHandler;
import org.buaa.algorithm.NettyClient;
import org.buaa.algorithm.NettyServer;
import org.buaa.utils.PropertiesUtils;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Properties;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Main {
    public static void runMaster(Properties properties) throws InterruptedException, IOException {
        int slaveAmount = Integer.parseInt(properties.getProperty("slave.amount"));
        ConcurrentLinkedQueue<Thread> threads = new ConcurrentLinkedQueue<>();
        for (int i = 0; i < slaveAmount; i++) {
            String slaveName = "slave" + i;
            File sendFile = new File(properties.getProperty("data.send.path") + "file" + i + ".txt");
            File receiveFile = new File(properties.getProperty("data.receive.path") + slaveName + ".txt");
            String command = properties.getProperty("data.generate.process")
                    + " bigint " + sendFile.getPath() + " " + properties.getProperty("data.generate.rows");

            Thread thread = new Thread(() -> {
                try {
                    System.out.println("执行命令：" + command);
                    // 生成文件
                    Process process = Runtime.getRuntime().exec(command);
                    process.waitFor();
                    process.destroy();

                    System.out.println("执行完成：" + command);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                NettyServer server = new NettyServer();
                ChannelInboundHandlerAdapter serverHandler = new AlgoServerHandler(sendFile.getPath());
                // 发送文件
                System.out.println("Server for " + slaveName + " start...");
                server.run(Integer.parseInt(properties.getProperty(String.format("master.%s.port", slaveName))), serverHandler);
                System.out.println("Server for " + slaveName + " close...");
                NettyClient client = new NettyClient();
                ChannelInboundHandlerAdapter clientHandler = new AlgoClientHandler(receiveFile.getPath());
                System.out.println("开始从"
                        + properties.getProperty(slaveName + ".ip") + ":" + properties.getProperty(slaveName + ".port")
                        + "接收文件： " + receiveFile.getPath() + "...");
                // 接收slave排序完的文件
                client.run(properties.getProperty(slaveName + ".ip")
                        , Integer.parseInt(properties.getProperty(slaveName + ".port"))
                        , clientHandler);

                System.out.println("完成接收文件：" + receiveFile.getPath());
                // 执行完成移除线程
                threads.remove(Thread.currentThread());
            });
            // 线程加入队列
            threads.add(thread);
        }
        // 启动所有线程
        for (Thread t : threads) {
            t.start();
            Thread.sleep(1000);
        }
        // 等待所有线程执行结束
        for (Thread t : threads) {
            t.join();
        }
        // 线程队列完成，合并文件
        File receivePath = new File(properties.getProperty("data.receive.path"));
        File[] receiveFiles = receivePath.listFiles();
        ArrayList<BufferedReader> readers = new ArrayList<>();
        assert receiveFiles != null;
        for (File f : receiveFiles) {
            if (f.getName().startsWith("slave")) {
                readers.add(new BufferedReader(new FileReader(f.getPath())));
                System.out.println("BufferedReader add: " + f.getPath());
            }
        }
        // 设置读取缓冲数组
        BigInteger[] readerBuffer = new BigInteger[readers.size()];

        for (int i = 0; i < readers.size(); i++) {
            BufferedReader reader = readers.get(i);
            String num;
            if ((num = reader.readLine()) != null) {
                if (!num.isEmpty()) {
                    readerBuffer[i] = new BigInteger(num);
                }
            }
        }
        System.out.println("文件merge开始...");
        BufferedWriter writer = new BufferedWriter(new FileWriter(properties.getProperty("data.merge.file")));
        int minReader = 0;
        boolean isOver = false;
        while (!isOver) {
            int count = 0;
            // 找到最小的索引
            for (int i = 0; i < readerBuffer.length; i++) {
                if (readerBuffer[i] == null) {
                    count++;
                } else if (readerBuffer[minReader] == null || readerBuffer[minReader].compareTo(readerBuffer[i]) > 0) {
                    minReader = i;
                }
            }
            // 如果所有readerBuffer中的数字都为null，结束Merge
            if (count == readerBuffer.length) {
                isOver = true;
            } else {
                // 写出最小的number
                writer.write(readerBuffer[minReader].toString() + "\n");
                // 读取下一个number
                String num = readers.get(minReader).readLine();
                if (num != null && !num.isEmpty()) {
                    readerBuffer[minReader] = new BigInteger(num);
                } else readerBuffer[minReader] = null;
            }
        }
        for (BufferedReader reader : readers) {
            reader.close();
        }
        writer.flush();
        writer.close();
        System.out.println("文件merge结束...");
    }

    public static void runSlave(Properties properties) throws IOException, InterruptedException {
        String slaveName = properties.getProperty("slave.name");
        System.out.println("slave.name=" + slaveName);
        // 接收文件
        NettyClient nettyClient = new NettyClient();
        AlgoClientHandler handler = new AlgoClientHandler(properties.getProperty(slaveName + ".receive.file"));
        // 设置关闭等待
        handler.isClose = false;
        Thread receviceClient = new Thread(() -> {
            nettyClient.run(properties.getProperty("master.ip")
                    , Integer.parseInt(properties.getProperty(String.format("master.%s.port", slaveName)))
                    , handler);
        });
        receviceClient.start();
        while (!handler.isOver) {
            Thread.sleep(500);
        }
        String command = String.format("%s %s %s %s %s"
                , properties.getProperty("data.sort.process")
                , properties.getProperty(slaveName + ".receive.file")
                , properties.getProperty(slaveName + ".send.file")
                , properties.getProperty("data.sort.type")
                , properties.getProperty("slave.thread.amount"));

        // 执行C++多线程排序
        System.out.println("执行命令：" + command);
        Process process = Runtime.getRuntime().exec(command);
        process.waitFor();
        process.destroy();
        System.out.println("执行完成：" + command);

        // 发送排序完成的文件
        NettyServer server = new NettyServer();
        ChannelInboundHandlerAdapter serverHandler = new AlgoServerHandler(properties.getProperty(slaveName + ".send.file"));
        Thread sendServer = new Thread(() -> {
            server.run(Integer.parseInt(properties.getProperty(slaveName + ".port")), serverHandler);
        });
        // 发送文件
        sendServer.start();
        // 通知Server关闭连接
        handler.isClose = true;
        sendServer.join();
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        long startTime = System.currentTimeMillis();
        Properties properties = PropertiesUtils.load("./run.properties");
        if (properties.getProperty("mode").equals("master")) {
            runMaster(properties);
        } else if (properties.getProperty("mode").equals("slave")) {
            runSlave(properties);
        } else {
            System.out.println("参数错误！");
        }
        long endTime = System.currentTimeMillis();
        System.out.println("程序用时：" + (endTime - startTime) + "ms...");
    }
}
