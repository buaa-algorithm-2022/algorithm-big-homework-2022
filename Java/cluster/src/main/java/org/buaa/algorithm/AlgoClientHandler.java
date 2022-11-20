package org.buaa.algorithm;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.util.CharsetUtil;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class AlgoClientHandler extends ChannelInboundHandlerAdapter {
    File file;
    BufferedWriter bw;
    public boolean isOver = false;
    String buffer = "";

    public boolean isClose = true;

    public AlgoClientHandler(String path) {
        this.file = new File(path);
    }

    @Override
    public void channelActive(ChannelHandlerContext ctx) throws Exception {

        System.out.println("Client建立连接：" + ctx.channel().remoteAddress());
        if (!file.exists()) {
            if (file.createNewFile()) {
                System.out.println("创建文件：" + file.getPath());
            }
        }
        System.out.println("写文件：" + file.getPath());
        // 这种方式会有结尾多出脏数据的bug
        // bw = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8, StandardOpenOption.WRITE);
        bw = new BufferedWriter(new FileWriter(file));
    }

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        if (!isOver) {
            ByteBuf byteBuf = (ByteBuf) msg;
            String lines = byteBuf.toString(CharsetUtil.UTF_8);
            buffer += lines;
            byteBuf.release();
        }
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
//        System.out.print("buffer:" + buffer);
        if (buffer.contains("over")) {
            buffer = buffer.replaceAll("over", "");
            isOver = true;
        }
        bw.write(buffer);
        // 写完置空buffer
        buffer = "";
        if (isOver) {
            bw.flush();
            bw.close();
            System.out.println("写文件结束： " + file.getPath());
            // 等待排序结束
            while(!isClose) {
                Thread.sleep(500);
            }
            ctx.writeAndFlush(Unpooled.copiedBuffer("over", CharsetUtil.UTF_8));
            ctx.channel().closeFuture();
            System.out.println("Client断开连接: " + ctx.channel().remoteAddress());
        }
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        ctx.close();
    }
}
