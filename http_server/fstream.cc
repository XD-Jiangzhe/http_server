#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <memory>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main()
{
/*()	std::ifstream f("./hello.html",std::ios::out);

	string line, context;
		while(getline(f, line))
		{
			context += line;
		}

		std::cout<<context<<std::endl;*/


/*		ifstream  ifs("./home_page/mime.type", std::ios::in);
				
				map<string, string> table;

				string line;
				while(getline(ifs, line))
				{
					istringstream ists(line);
					string first,second;
					ists>>first>>second;

					table.insert(make_pair(second, first));
				}

				ifs.close();*/

/*		for(auto const&i : table)
			cout<<i.first<<" "<<i.second<<endl;*/

/*		ifstream  sfs("./home_page/mime.type", std::ios::in);		//in是读啊，就是内核读文件
	
		ofstream ofs("haha.txt", std::ios::out);
		if(ofs.fail())
			cout<<"fail"<<endl;
		else 
			cout<<"success"<<endl;
		ofs <<sfs.rdbuf();

		ostringstream oss;
		oss<<sfs.rdbuf();
		cout<<string(oss.str())<<endl;*/
/*
		set<int> s{1,2,3,4};
		auto pos =find (s.begin(), s.end(), 3);

//		auto pos = s.find(3);
		cout<<*pos<<endl;*/
/*		string path("/home/router/Documents/use_muduo/http_server/home_page/index.html");
		ifstream ifs(path, std::ios::in);

				if(ifs.fail())
				{
					std::cout<<"fail"<<" "<<std::endl;
				}

				string line, content;
				while(getline(ifs, line))
				{
					cout<<line<<endl;
					content += line;
				}

				std::cout<<"the content is "<<content<<std::endl;

				cout<<ifs.rdbuf();*/

	string s("asdfaf");
	const char *a = s.c_str();

	auto p = [](char *p){delete[] p;};


	shared_ptr<char>pa(new char[s.size()], p); 

/*	char *pa = new char[s.size()];*/

	memcpy(pa.get(), a, s.size());

	string re(pa.get(), pa.get()+s.size());
	cout<<re<<endl;
/*	delete [] pa;*/

	return 0;
}
