#include<iostream>
#include<string>
using namespace std;

#include"mymap.h"
#include"myset.h"

//void func(const jyf::map<int, int>& m)
//{
//	//auto mit = m.begin();
//	jyf::map<int, int>::const_iterator mit = m.begin();
//	while (mit != m.end())
//	{
//		// 不能修改key，不能修改value
//		//mit->first = 1;
//		//mit->second = 2;
//
//		cout << mit->first << ":" << mit->second << endl;
//		++mit;
//	}
//	cout << endl;
//}

int main()
{
	jyf::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));

	//bit::map<int, int>::iterator mit = m.begin();
	auto mit = m.begin();
	while (mit != m.end())
	{
		// 不能修改key，可以修改value
		//mit->first = 1;
		mit->second = 2;

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;

	//func(m);

	for (const auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	jyf::set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(2);
	s.insert(12);
	s.insert(22);
	s.insert(332);
	s.insert(7);
	jyf::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// 不应该允许修改key
	/*	if (*it % 2 == 0)
		{
			*it += 10;
		}*/

		cout << *it << " ";
		++it;
	}
	cout << endl;

	//for (const auto& e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	jyf::map<string, string> dict;
	dict.insert(make_pair("sort", "xxx"));
	dict["left"]; // 插入

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	dict["left"] = "左边"; // 修改
	dict["sort"] = "排序"; // 修改
	dict["right"] = "右边"; // 插入+修改

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;


	return 0;
}