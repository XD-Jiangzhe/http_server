#ifndef HEAD_HTTPCONTEXT
#define HEAD_HTTPCONTEXT

#include <muduo/base/Timestamp.h>
#include <muduo/net/Buffer.h>
#include "HttpRequest.hpp"

#include <map>
#include <stdio.h>
#include <algorithm>

namespace muduo{

namespace net{
class HttpContext{

	public:

		enum Httpparsestate{
			RequestLine,							//正在解析请求行 GET / HTTP/1.1
			RequestHeader,							//正在解析请求头 Connecthon: keep-alive \r\n
			RequestBody,							//正在解析请求的内容	
			ParseAll								//已经全部解析完毕
		};

		HttpContext():state_(RequestLine){}

		bool parseRequest(/*string *buf*/Buffer *buf, Timestamp arrivetime);			
		//用来解析当前的请求头是否解析成功,即拿到一个buf查看是否是正常的请求

		bool parseAll()
		//查看是否解析完毕了
		{
			return state_== ParseAll;
		} 
						
		HttpRequest getHttpRequest()
		{
			return hq_;
		}

		//清空HttpRequest 的内容,这里将成员变量与一个栈上的新建对象进行交换，交换之后栈上对象释放掉了
		void clear()
		{
			HttpRequest newhq;
			hq_.swap(newhq);
			state_ = RequestLine;				
		}

		bool parseHttpRquestLine(char *begin, char* end, int &len);			//解析http 第一行的请求头字段

	private:
		HttpRequest 	hq_;
		Httpparsestate  state_;
		
};

}

}

#endif