#include<iostream>
using namespace std;

#include "HashTable.h"


int main()
{
	hash_bucket::HashTable<int, int> ht;
	int a[] = { 1,111,4,7,15,25,44,9 };
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}
	ht.Print();

	ht.Insert(make_pair(14, 14));
	ht.Print();

	ht.Insert(make_pair(24, 24));
	ht.Print();

	ht.Insert(make_pair(34, 34));
	ht.Print();

	ht.Erase(44);
	ht.Erase(4);
	ht.Erase(24);
	ht.Print();

	hash_bucket::HashTable<string, string> dict;
	dict.Insert(make_pair("sort", "����"));
	dict.Insert(make_pair("left", "xxx"));
	dict.Insert(make_pair("insert", "����"));
	dict.Insert(make_pair("string", "�ַ���"));
	dict.Insert(make_pair("bucket", "Ͱ"));

	auto dret = dict.Find("left");
	//dret->_kv.first = "xx";
	dret->_kv.second = "���";
	dict.Print();

	return 0;
}