package org.buaa.algorithm;

import io.netty.bootstrap.Bootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;


public class NettyClient {
    public void run(String ip, int port, ChannelInboundHandlerAdapter handler) {
        //处理连接请求的NioEventLoopGroup
        NioEventLoopGroup nioEventLoopGroup = new NioEventLoopGroup();
        //服务对象
        Bootstrap bootstrap = new Bootstrap();
        //配置服务参数
        bootstrap.group(nioEventLoopGroup)
                .channel(NioSocketChannel.class)
                .handler(new ChannelInitializer<SocketChannel>() {
                    @Override
                    protected void initChannel(SocketChannel socketChannel) throws Exception {
                        socketChannel.pipeline().addLast(handler);
                    }

                    @Override
                    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
                        super.exceptionCaught(ctx, cause);
                    }

                    @Override
                    public void handlerAdded(ChannelHandlerContext ctx) throws Exception {
                        super.handlerAdded(ctx);
                    }
                });
        //连接服务器端
        ChannelFuture connect = bootstrap.connect(ip, port);
        try {

            //关闭连接
            connect.channel().closeFuture().sync();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            //关闭连接
            nioEventLoopGroup.shutdownGracefully();
        }
    }
}
