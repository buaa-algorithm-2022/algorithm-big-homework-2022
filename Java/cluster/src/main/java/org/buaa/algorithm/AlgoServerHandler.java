package org.buaa.algorithm;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.util.CharsetUtil;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public class AlgoServerHandler extends ChannelInboundHandlerAdapter {
    String buffer = "";
    File file;
    public AlgoServerHandler(String path) {
        this.file = new File(path);
    }

    @Override
    public void channelActive(ChannelHandlerContext ctx) throws Exception {
        System.out.println("Server建立连接：" + ctx.channel().remoteAddress());
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(file));
            String msg;
            while ((msg = reader.readLine()) != null) {
                ctx.writeAndFlush(Unpooled.copiedBuffer(msg + "\n", CharsetUtil.UTF_8));
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        ctx.writeAndFlush(Unpooled.copiedBuffer("over", CharsetUtil.UTF_8));
    }

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        ByteBuf byteBuf = (ByteBuf) msg;
        String strMsg = byteBuf.toString(StandardCharsets.UTF_8);
        buffer += strMsg;
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
        if (buffer.contains("over")) {
            System.out.println("断开连接：" + ctx.channel().remoteAddress());
            ctx.channel().close();
            ctx.channel().parent().close();
        }
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        ctx.close();
    }
}
