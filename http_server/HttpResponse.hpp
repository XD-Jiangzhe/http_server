#ifndef HEAD_HTTPRESPONSE
#define HEAD_HTTPRESPONSE

#include <muduo/base/Types.h>
#include <muduo/net/Buffer.h>

#include <map>
namespace muduo{

namespace net{

	class HttpResponse{

		public:
			HttpResponse():connection_(true){}								// HTTP/1.1 默认长连接

			enum HttpstatusCode
			{
				unknown =0,
				ok = 200,
				move_permanently = 301,
				bad_request = 400,
				not_found = 404
			};

			void set_status(HttpstatusCode code_)
			{
				status_ = code_;
			}

			void set_status_message_(const string &message)
			{
				status_message_ = message;
			}

			void set_connection(bool t)
			{
				connection_ = t;
			}

			bool get_connection()
			{
				return connection_; 
			}

			void append_to_buffer(Buffer *buf);

			void add_header_(const string &key,const  string &content)
			{
				header_[key] = content;
			}

			void add_content_type(const string &content_type)
			{
				header_["Content-Type"]= content_type;
			}

			void set_body(const string &body)
			{
				body_ = body;
			}

			const string get_body()const
			{
				return body_;
			}

		private:
			std::map<string, string> header_;
			HttpstatusCode status_;
			string status_message_;
			bool connection_;
			string body_;
	};

}

}
#endif