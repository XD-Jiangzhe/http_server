#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <muduo/base/StringPiece.h>

#include "HttpContext.hpp"
#include "HttpResponse.hpp"
#include "HttpRequest.hpp"
#include "HttpServer.hpp"

using namespace std;

int main()
{

/*	char *a = NULL;
	size_t l = 4096;

	getline(&a, &l, stdin);

	int len1 = strlen(a);

//	cout<<len<<endl;

	auto pos = find(a, a+len1, ' ');
//	cout<<*(pos-1)<<endl;

	string s(a,pos);*/

/*	cout<<s.size()<<endl;

	cout<<s<<endl;*/


	muduo::net::HttpContext ht;
	char ex[]="GET / HTTP/1.1\r\n"\
					"adf: afdaf\r\n";
	std::string ex1 = "GET /";
	std::string ex2 = "G";
	char sa[]="GET / HTTP/1.1\r\n" \
					"adf: afdf\r\n" \
					"adfasdf: adfafd\r\n"
					"\r\n";
	char sa1[]="GET / HTTP/1.1\r\n" \
					"adf: afdf\r\n" \
					"1: 1\r\n"
					"\r\n";
/*
	muduo::string ex3(sa);

	muduo::string ex5(sa1);
	int len =0;
	
	muduo::Timestamp ar;
//	ht.parseRequest(&ex3, ar);

	ht.parseRequest(&ex5, ar);*/
	//ht.parseRequest(&ex4, ar);


	return 0;
}