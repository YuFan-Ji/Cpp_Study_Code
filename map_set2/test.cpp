#include<iostream>
#include<set>
#include<map>


using namespace std;


//void test_map01()
//{
//	map<string, string> m;
//	pair<string, string> kv1("insert", "����");
//	m.insert(kv1);
//
//	m.insert(pair<string, string>("erase", "ɾ��"));
//
//	// c++ 98
//	m.insert(make_pair("sort", "����"));
//
//	// c++ 11 ֧�ֶ�����Ĺ��캯����ʽ����ת��
//	m.insert({ "string", "�ַ���" });
//
//
//}

//void test_map2()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("string", "�ַ���"));
//	dict.insert(make_pair("sort", "����"));
//	dict.insert(make_pair("insert", "����"));
//
//	// �����룬�����ǣ���������У�ֻ�Ƚ�key��value����ͬ����ν
//	// key�Ѿ����˾Ͳ�������
//	dict.insert(make_pair("insert", "xxxx"));
//
//}

//void test_map2()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("string", "�ַ���"));
//	dict.insert(make_pair("sort", "����"));
//	dict.insert(make_pair("insert", "����"));
//
//	// �����룬�����ǣ���������У�ֻ�Ƚ�key��value����ͬ����ν
//	// key�Ѿ����˾Ͳ�������
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
	// ͳ�ƴ���
	string arr[] = {"zzz", "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", 
		             "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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
//	//dict.insert(make_pair("string", "�ַ���"));
//	//dict.insert(make_pair("sort", "����"));
//	//dict.insert(make_pair("insert", "����"));
//
//	//cout << dict["sort"] << endl; // ���ҺͶ�
//	//dict["map"];                  // ����
//	//dict["map"] = "ӳ��,��ͼ";     // �޸�
//	//dict["insert"] = "xxx";       // �޸�
//	//dict["set"] = "����";         // ����+�޸�
//
//	multimap<string, string> s;
//
//}

int main()
{
	test_map3();

	return 0;
}

