/*
	Http/1.1 默认的是长连接
	HTTP/1.0 默认的是短连接
	短连接： 即每次发送完所有的数据就断开链接， 不存在 长期占用系统资源的连接，所有的连接都是有用的
			短连接的请求头中有  Connection: Close\r\n
			短连接中系统每次发送完响应报，就会与之断开
			conn->shutdown()

	长连接： 每次发送完之后不断开与用户的连接，用户连接一直占用系统资源，直到用户主动断开为止
			长连接的请求头中有 Connection： Keep-Alive\r\n
			每次发送完以后，应该清空解析的request，不然会影响下次的解析
*/

#include "HttpServer.hpp"

#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>
#include <boost/any.hpp>

#include <map>
#include <functional>
#include <iostream>
using namespace muduo;
using namespace muduo::net;



using namespace std::placeholders;
class HttpContext;

void default_http_callback(const HttpRequest &req, HttpResponse* resp)
{
	resp->set_status_message_("NOT FOUND");				//const char* 
	resp->set_connection(true);
	resp->set_status(HttpResponse::HttpstatusCode::not_found);
	resp->set_body("404 had not found");
}

HttpServer::HttpServer(EventLoop *loop,
			const InetAddress &Inet,
			const string& nameArg,
			 TcpServer::Option option ):tcp_(loop, Inet, nameArg, option), httpcb(default_http_callback)
{
	tcp_.setConnectionCallback(std::bind(&HttpServer::onConnection, this, _1));
	tcp_.setMessageCallback(std::bind(&HttpServer::onMessage, this, _1, _2, _3));
}

void HttpServer::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime)			//这里TcpConnection已经是指针了
{
	HttpContext* context = boost::any_cast<HttpContext>(conn->getMutableContext());		
	//将连接中的boost::any 变成 context对象，用来确定解析缓冲区中文本的方式，比如缓冲区中是http 还是别的协议之类的，绑定一个解析对象
	//conn->getMutableContext() 得到该成员对象
	if(!context->parseRequest(buf, receiveTime))
	{
		std::cout<<"bad request"<<std::endl;
		conn->send("HTTP/1.1 400 Bad Requst\r\n\r\n");
		conn->shutdown();
	}
	if(context->parseAll())																	//解析完成了
	{
		auto temp = context->getHttpRequest();
		onRequest(conn, temp);																
		//如果是长连接需要清空 tcpconnection 中的 conn->getMutableContext() 中的 request的值，否则会影响到下次的解析结果
		
		context->clear();
		
	}
}

void HttpServer::onConnection(const TcpConnectionPtr &conn)
{
	conn->setContext(HttpContext());						
	//设置解析的协议方式
	
}


void HttpServer::onRequest(const TcpConnectionPtr &conn, const HttpRequest &re)
{
	HttpResponse httpr;																			//这里构造一个相应包，根据请求包

	string type = re.find_head_("Connection");
	
	if(type=="close")																			//短连接
	{
/*		std::cout<<type<<std::endl;*/
		httpr.set_connection(false);
		httpr.add_header_("Connection", "close");
	}
	else 																						//长连接
	{
		httpr.set_connection(true);
		httpr.add_header_("Connection", "keep-alive");
	}

/*	std::cout<<"here before httpcb"<<std::endl;*/
	httpcb(re, &httpr);																		
	//将剩余的部分未设置的部分放入到httpcallback，让用户自己去设置,输入解析好的用户请求，放入准备好的响应
	Buffer buf;
	httpr.append_to_buffer(&buf);
	conn->send(&buf);

	if(type == "close")
		conn->shutdown();													//短连接的话就关闭

}
void HttpServer::start()
{
	tcp_.start();
}

