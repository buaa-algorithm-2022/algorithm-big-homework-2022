package org.buaa.algorithm;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.util.CharsetUtil;

import java.io.BufferedWriter;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;

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
        bw = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8, StandardOpenOption.WRITE);
    }

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        ByteBuf byteBuf = (ByteBuf) msg;
        String lines = byteBuf.toString(CharsetUtil.UTF_8);
        buffer += lines;

    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
//        System.out.print(buffer);
        if (buffer.contains("over")) {
            buffer = buffer.replaceAll("over", "");
            isOver = true;
        }
        bw.write(buffer);
        bw.flush();
        buffer = "";
        if (isOver) {
            bw.close();
            System.out.println("写文件结束...");
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
