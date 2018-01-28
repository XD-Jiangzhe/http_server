#include "HttpServer.hpp"
#include "HttpResponse.hpp"
#include "Util.hpp"

#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>

#include <fstream>
#include <iostream>
#include <memory>
#include <cstring>


using namespace muduo;
using namespace muduo::net;



void callback(const HttpRequest& req,  HttpResponse* res)
{	

	if(const_cast<HttpRequest&>(req).getmethod() == HttpRequest::GET)				
	//呵呵哒，这里没有处理带有body 的 request， 理论上来讲应该将带数据的get和post 一并处理，在低下有个 
	{
		std::string temp_path = util::pathcontext(req.get_path().c_str());
		std::string temp_suffix =util::getsuffix(temp_path);
		std::string temp_type = util::getmime_type(temp_suffix);
		std::string temp_content = util::GetContent(temp_path);

	//这里因为可能是二进制文件，所以会有0x00 这种骚东西，会把string的拷贝构造函数截断，所以要使用memecpy 这种原始的拷贝方式								
		const char* raw = temp_content.c_str();
		auto p = [](char *p){delete []p;};

		std::shared_ptr<char> pcon(new char[temp_content.size()], p);			//切记 智能指针在管理 数组的生命周期的时候一定要自己定制 删除器

		memcpy(pcon.get(), raw, temp_content.size());
		string real_content(pcon.get(), pcon.get()+temp_content.size());


		if(temp_content.empty())
		{
			res->set_status_message_("NOT FOUND");
			res->set_status(muduo::net::HttpResponse::HttpstatusCode::not_found);
		}
		else
		{
			res->set_status(muduo::net::HttpResponse::HttpstatusCode::ok);
			res->set_status_message_("OK");
			res->add_content_type(string(temp_type.c_str()));
			res->set_body(real_content);
			res->add_header_("server", "jiangzhe");
		}
	}
	else if(const_cast<HttpRequest&>(req).getmethod() == HttpRequest::POST)			
	//这里可以仿照tinyhttpd的写法，fork一个子进程，然后将数据传入到一个cgi 当中,这部分并未实现，养猪
	{

	}

}

int main()
{
	EventLoop loop;
	InetAddress inet(1995);

	HttpServer hs(&loop, inet, "httpd");
	hs.set_httpserver_thread_num(10);

	hs.setHttpCallback( callback);			
	//如果原来写的是引用，就必须要绑定一个对象才能使用。。。比如function

	hs.start();
	loop.loop();

	return 0;
}