#include "HttpContext.hpp"
#include <muduo/net/Buffer.h>

#include <cassert>
#include <iostream>
#include <algorithm>

using namespace muduo;
using namespace muduo::net;


bool HttpContext::parseHttpRquestLine(char *begin, char* end, int  &len)
//HTTP 请求头的第一行的结构
// GET / HTTP/1.1 /r/n
{
/*	std::cout<<string(begin,end)<<std::endl;*/
	state_ = RequestLine;
	bool linestate = false;

	char* start = begin;
	char* second_space;

	string end_s("\r\n");

	string method;
	string path;
	string version;

	auto first_space = std::find(start, end+1, ' ');

	do {
	//这里用do{}while(0); 来代替了原先写的goto 使得代码变得易读了许多，因为 goto 之后是不能再进行变量的声明的，所以只能放在前面，这样做之后声明就可以放在下面了
	//刚刚看别人的博客 学的 嘿嘿

		if(first_space != end+1 && hq_.set_method_stat(start, first_space)){}			//取出request line的method get, post...
		else 																	//设置hq_ 的 method 
			break;

		start = first_space +1;
		second_space = std::find(start, end+1, ' ');

		if(second_space != end+1 && hq_.set_path(start, second_space)){}		//设置 hq_ 的path 变量
		else 
			break;
		start = second_space+1;
		if(start+8 < end && hq_.set_version(start, start+8)){}				//设置http/1.1 或者 http/1.0 版本
		else 
			break;

		start += 8;
		if(string(start, start+2) != end_s)										//匹配 最后的 /r/n 
			break;
	/*	std::cout<<"here  jiexi first success"<<std::endl;*/

		linestate = true;
		len = start+2-begin;
		state_ = RequestHeader;													//将状态设置为解析头部，请求第一行解析完了
	//	std::cout<<string(begin,start+len_requestline)<<std::endl;
	
	}while(0);

	return linestate;
}

bool HttpContext::parseRequest(Buffer *buf/*string *buf*/, Timestamp arrivetime)
{
	char request_end[]="\r\n\r\n";
	
	int line_len = 0;
	char* begin = 	buf->beginWrite()-buf->readableBytes();
	char* end 	=	buf->beginWrite();
/*	char *begin = &*buf->begin();
	char *end   = &*buf->end();*/

	if(!parseHttpRquestLine(begin, end, line_len))
		return false;

	assert(state_ == RequestHeader);

	char* request_start = begin+line_len;
	string Request(request_start, end);

	int end_place = Request.find(request_end);
	if(end_place == -1)
		return false;
	else 
		Request = string(request_start, request_start+end_place+2);				//直接找结尾的部分\r\n，找不到就直接退

//下面是找各个对应的部分Connection: keep-alive

	int end_line=0,temp =0;																
	char* temp_start = request_start;
	char* temp_end = request_start+end_place+2;
	char* real_end = request_start+end_place+4;
	string linea,first,second;

	int body_len=0;

	try{
		while(temp_start < temp_end)
		{
			end_line = string(temp_start, temp_end).find("\r\n");
			if(end_line == -1)
				goto re;

			linea=string(temp_start, temp_start+end_line+1);
			
			temp =linea.find(':');
			if(temp == -1)
				goto re;

			first= string(temp_start, temp_start+temp);
			second= string(temp_start+temp+2, temp_start+end_line);

			hq_.header_insert(first, second);									
			temp_start += end_line+2;
		}
	}catch(...)
	{
		goto re;
	}

	state_ = RequestBody;							//解析post 请求 
	do{

		if(hq_.getmethod() == HttpRequest::GET)
		{
			do{
				string path_all =hq_.get_path();
				int temp = 0;
				if((temp=path_all.find('?'))==-1)
					break;
				else
				{
					hq_.set_path(&*path_all.begin(), &*(path_all.begin()+temp));
					hq_.set_body(&*path_all.begin()+temp+1, &*path_all.end());
					std::cout<<hq_.getbody()<<std::endl;
				}

			}while(0);

			buf->retrieveUntil(request_start+end_place+4);		//将解析好的头部在缓冲区中清出去
			state_ = ParseAll;								//先不实现post，先把get请求的写完，这里状态变成解析完成
			return true;
		}
		else if(hq_.getmethod() == HttpRequest::POST)
		{
			try
			{
				string p = hq_.find_head_("Content-Length");
				if(p.size() == 0)
					break;
				else 
				{
					body_len = stoi(p);									//找到post 的string 长度，然后将这部分长度截取出来		
					hq_.set_body(real_end+1, real_end+1+body_len);		//取出 post 的body 
				}	

				state_ = ParseAll;
				buf->retrieveUntil(request_start+end_place+4+body_len);
				return true;
			
			}
			catch(...)
			{
				break;
			}

		}
		
		
	}while(0);

re:
	HttpRequest a;
	hq_.swap(a);										//如果失败就清空之前保存的httprequest 请求
	return false;
}

