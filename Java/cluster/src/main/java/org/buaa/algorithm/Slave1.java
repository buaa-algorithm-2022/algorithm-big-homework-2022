package org.buaa.algorithm;

public class Slave1 {
    public static void main(String[] args) {
        NettyClient nettyClient = new NettyClient();
        AlgoClientHandler handler = new AlgoClientHandler("/Users/zhangliang/code/useful_code/selfcode/src/main/java/algo/_data/file1.txt");
        nettyClient.run("127.0.0.1", 8888, handler);
    }
}
