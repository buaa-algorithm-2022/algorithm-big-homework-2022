package org.buaa.algorithm;

import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.*;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioServerSocketChannel;


/**
 * @Author zhangliang
 * @Despriction
 * @Date 2022/11/9 00:53
 */
public class NettyServer {
    public void run(int port, ChannelInboundHandlerAdapter handler) {
        //boosGroup处理连接请求
        NioEventLoopGroup boosGroup = new NioEventLoopGroup();
        //workGroup处理真正的业务逻辑
        NioEventLoopGroup workGroup = new NioEventLoopGroup();
        //服务端启动对象
        ServerBootstrap bootstrap = new ServerBootstrap();
        //配置启动对象参数
        //设置两个线程组
        bootstrap.group(boosGroup, workGroup)
                //channel类型为NioServerSocketChannel
                .channel(NioServerSocketChannel.class)
                //线程队列的连接个数
                .option(ChannelOption.SO_BACKLOG, 128)
                //线程队列的状态
                .childOption(ChannelOption.SO_KEEPALIVE, true)
                //配置子处理器（匿名类）
                .childHandler(new ChannelInitializer<SocketChannel>() {
                    @Override
                    protected void initChannel(SocketChannel socketChannel) throws Exception {
                        socketChannel.pipeline()
                                .addLast(handler);
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
        try {
            //绑定端口
            ChannelFuture channelFuture = bootstrap.bind(port).sync();
            //关闭通道监听
            channelFuture.channel().closeFuture().sync();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            //关闭连接
            boosGroup.shutdownGracefully();
            workGroup.shutdownGracefully();
        }
    }
}
