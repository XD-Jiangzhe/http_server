#include "HttpResponse.hpp"
#include <muduo/net/Buffer.h>

#include <stdio.h>
#include <string.h>

using namespace muduo;
using namespace muduo::net;

void HttpResponse::append_to_buffer(Buffer *buf)							//此函数主要是用来造响应头，不包含body
{

	char line[40];
	sprintf(line, "HTTP/1.1 %d %s", status_, status_message_.c_str());

	buf->append(line, strlen(line));											//添加第一行的响应头
	buf->append("\r\n", 2);

	buf->append("Content-length: ",16);										//添加 Content-length: 数字
	char length[40];
	sprintf(length, "%ld", body_.size());
	buf->append(length, strlen(length));
	buf->append("\r\n", 2);

	for(auto const &i : header_)
	{
		buf->append(i.first);
		buf->append(": ", 2);
		buf->append(i.second);
		buf->append("\r\n", 2);
	}
	buf->append("\r\n", 2);

	buf->append(get_body());
}