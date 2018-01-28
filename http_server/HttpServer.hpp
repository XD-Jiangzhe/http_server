#ifndef HEAD_HTTPSERVER
#define HEAD_HTTPSERVER

#include "HttpContext.hpp"
#include "HttpResponse.hpp"
#include "HttpRequest.hpp"

#include <muduo/net/TcpServer.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/base/Logging.h>

#include <functional>


namespace muduo
{
	namespace net
	{
		class HttpServer
		{

			public:
				typedef std::function<void(const HttpRequest&, HttpResponse*)> HttpCallback;

				HttpServer(EventLoop *loop,
							const InetAddress &Inet,
							const string& nameArg,
							 TcpServer::Option option = TcpServer::kNoReusePort
							);
				
				void start();

				void setHttpCallback(HttpCallback cb)
				{
					httpcb = cb;
				}

				void set_httpserver_thread_num(int num)
				{
					tcp_.setThreadNum(num);
				}

				~HttpServer()
				{
				}

			private: 
				void onConnection(const TcpConnectionPtr &conn);
				void onMessage(const TcpConnectionPtr& conn,
                 				Buffer* buf,
                 				Timestamp receiveTime);

				void onRequest(const TcpConnectionPtr &conn, 
								 const HttpRequest &re);
				//在onMessage 中回调onRequest,来对收到的message 进行解析，从而判断是否收到了一个完整的请求头
				
				HttpCallback httpcb;
				//这里当request到来用onrequest 解析完以后，回调HttpCallback来向tcpconnection 发送Httpresponse 相应，这里用户可以自己定制相应的内容
				TcpServer tcp_;

		};

	}
}

#endif