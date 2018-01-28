#ifndef UTIL_HEAD
#define UTIL_HEAD

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
namespace muduo
{

	namespace net
	{

		namespace util
		{
			using std::string;
			using std::ifstream;
			using std::ofstream;
			using std::istringstream;
			using std::ostringstream;
			using std::map;

			std::string pathcontext(const string &path)
			{

				string basic = string("/home/router/Documents/use_muduo/http_server/home_page");

				if(path == "/")
				{
					return basic+"/index.html";							//这里如果默认是/则返回指定路径下的index.html文件
				}
				else 
				{
					return basic+path;
				}

			}

			//从路径中获取文件的拓展名，即最后一个.之后的部分
			const string getsuffix(const string &path)
			{
				std::cout<<path<<std::endl;
				auto i = path.rfind('.');

				return i==-1 ? "html":string(path.begin()+i+1, path.end());
			}

			//从mime.type中获取对应的文件的mime.type
			const string getmime_type(const string suffix)
			{
				ifstream  ifs("../home_page/mime.type", std::ios::in|std::ios::binary);

/*				std::cout<<suffix<<std::endl;*/
				
				map<string, string> table;

				string line;
				while(getline(ifs, line))
				{
					istringstream ists(line);
					string first,second;
					ists>>first>>second;

					table.insert(make_pair(second, first));
				}

				auto pos = table.find(suffix);

				ifs.close();

				return pos == table.end() ? "text/plain" : pos->second;
			}

			//通过文件路径来获取文件内容

			const string GetContent(const string &path)
			{
				ifstream ifs(path, std::ios::in);

				if(ifs.fail())
				{
					std::cout<<"fail"<<" "<<std::endl;
					return "";
				}

/*				string line, content;
				while(getline(ifs, line))
				{
					content += line;
				}

				std::cout<<"the content is "<<content<<std::endl;*/
				ostringstream oss;
				oss<<ifs.rdbuf();					//这里直接将 输入流 读到 字符串输出流中
				string si = oss.str();				//然后生成 输出字符串，就不需要 从上面那样一步一步地读了
													//这里只有 字符串流可以直接变成字符串，其他的不行

				return  si;						//只有 stingstream 可以转成字符串，其他不行
			}
		}

	}

}



#endif