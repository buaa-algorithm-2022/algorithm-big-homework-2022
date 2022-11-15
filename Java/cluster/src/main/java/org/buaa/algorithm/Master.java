package org.buaa.algorithm;

import io.netty.channel.ChannelInboundHandlerAdapter;

import java.io.IOException;

public class Master {
    public static void main(String[] args) throws InterruptedException, IOException {
        NettyServer server1 = new NettyServer();
        NettyServer server2 = new NettyServer();
        ChannelInboundHandlerAdapter handler1 = new AlgoServerHandler("/Users/zhangliang/code/useful_code/selfcode/src/main/java/algo/_data/test1.txt");
        ChannelInboundHandlerAdapter handler2 = new AlgoServerHandler("/Users/zhangliang/code/useful_code/selfcode/src/main/java/algo/_data/test2.txt");
        Thread t1 = new Thread(() -> server1.run(8888, handler1));
        Thread t2 = new Thread(() -> server2.run(8889, handler2));
        t1.start();
        t1.join();
        t2.start();
        t2.join();
        System.out.println("Master");
//        Runtime.getRuntime().exec("");
    }
}
