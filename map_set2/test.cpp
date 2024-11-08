#include<iostream>
#include<set>
#include<map>


using namespace std;


//void test_map01()
//{
//	map<string, string> m;
//	pair<string, string> kv1("insert", "插入");
//	m.insert(kv1);
//
//	m.insert(pair<string, string>("erase", "删除"));
//
//	// c++ 98
//	m.insert(make_pair("sort", "排序"));
//
//	// c++ 11 支持多参数的构造函数隐式类型转化
//	m.insert({ "string", "字符串" });
//
//
//}

//void test_map2()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("string", "字符串"));
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("insert", "插入"));
//
//	// 不插入，不覆盖；插入过程中，只比较key，value是相同无所谓
//	// key已经有了就不插入了
//	dict.insert(make_pair("insert", "xxxx"));
//
//}

//void test_map2()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("string", "字符串"));
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("insert", "插入"));
//
//	// 不插入，不覆盖；插入过程中，只比较key，value是相同无所谓
//	// key已经有了就不插入了
//	dict.insert(make_pair("insert", "xxxx"));
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		//cout << (*it).first << " : " << (*it).second << endl;
//		cout << it->first << " : " << it->second << endl;
//		++it;
//	}
//
//	dict.erase("string");
//	dict.clear();
//	for (auto e : dict)
//	{
//		cout << e.first << " : " << e.second << endl;
//	}
//}

void test_map3()
{
	// 统计次数
	string arr[] = {"zzz", "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", 
		             "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	map<string, int> countMap;

	//for (auto e : arr)
	//{
	//	auto it = countMap.find(e);
	//	if (it == countMap.end())
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		it->second++;
	//	}
	//}

	for (auto e : arr)
	{
		countMap[e]++;
	}

	for (const auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}
//
//
////int main()
////{
////	//test_map2();
////	test_map3();
////	return 0;
////}
//
//
//
//void test_map4()
//{
//	//map<string, string> dict;
//	//dict.insert(make_pair("string", "字符串"));
//	//dict.insert(make_pair("sort", "排序"));
//	//dict.insert(make_pair("insert", "插入"));
//
//	//cout << dict["sort"] << endl; // 查找和读
//	//dict["map"];                  // 插入
//	//dict["map"] = "映射,地图";     // 修改
//	//dict["insert"] = "xxx";       // 修改
//	//dict["set"] = "集合";         // 插入+修改
//
//	multimap<string, string> s;
//
//}

int main()
{
	test_map3();

	return 0;
}

