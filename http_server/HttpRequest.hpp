#ifndef HEAD_HTTPREQUEST
#define HEAD_HTTPREQUEST

#include <string.h>

#include <map>
#include <stdio.h>
#include <algorithm>

namespace muduo{

namespace net{



class HttpRequest{

	public:
		enum method
		{
			Invalid, GET, POST, HEAD, PUT, DELETE
		};
		enum version
		{
			unknown, http10, http11
		};

		HttpRequest():method_(Invalid), version_(unknown){}

		void setversion(version &s)
		{	
			version_ =s;
		}

		method get_method()
		{
			return method_;
		}

		const char* get_char_method()
		{
			const char* result = "UNKNOWN ";

			switch(method_)
			{
				case(GET):
					result = "GET";
					break;
				case(POST):
					result = "POST";
					break;
				case(HEAD):
					result = "HEAD";
					break;
				case(PUT):
					result = "PUT";
					break;
				case(DELETE):
					result = "DELETE";
					break;
				case(Invalid):
					result = "INVALID";
					break;
			}

			return result;
		}

		bool set_method_stat(char* start, char* end)
		{
			string temp(start, end);

			if(temp == "GET")
				method_ = GET;
			else if(temp == "POST")
				method_ = POST;
			else if(temp == "HEAD")
				method_ = HEAD;
			else if(temp == "PUT")
				method_ = PUT;
			else if(temp == "DELETE")
				method_ = DELETE;
			else 
				method_ = Invalid;

			return method_!= Invalid;			//如果有的话，设置 method_ 后就返回true， 如果没有到头部就返回false
		}

		bool set_path(char* start, char* end)
		{
			path_ = string(start, end);
	
			return true;
		}

		const string get_path() const
		{
			return path_;
		}

		bool set_version(char* start, char* end)
		{
			string ver(start, end);

			if(ver == "HTTP/1.1")
				version_ = http11;
			else if(ver == "HTTP/1.0")
				version_ = http10;
			else 
				version_ = unknown;

			return version_ != unknown;
		}

		version get_version()
		{
			return version_;
		}

		method getmethod(){return method_;}
		
		string getbody(){return body_;}
		
		string set_body(char* start, char* end)
		{
			body_ = string(start, end);
			return body_;
		}

		string gethead_(){

			string header_content;
			
			for(auto const &i : header_)
			{
				header_content += i.second;
			}

			return header_content;
		}


		string find_head_(const string &s) const
		{
			auto it = header_.find(s);
			return it == header_.end() ? NULL : it->second;
		}

		void header_insert(string first, string second)
		{
			header_.insert(make_pair(first, second));
		}

		std::map<string, string> get_map()
		{
			return header_;
		}

		void clear_map()
		{
			header_.clear();
		}

		void swap(HttpRequest &hq)
		{
			std::swap(method_, hq.method_);
			std::swap(version_, hq.version_);
			std::swap(path_, hq.path_);
			header_.swap(hq.header_);
			std::swap(body_, hq.body_);
		}

	private:
		method method_;
		version version_;
		string path_;
		std::map<string, string> header_;
		string body_;
};

}
}

#endif

