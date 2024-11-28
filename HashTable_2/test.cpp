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
	dict.Insert(make_pair("sort", "ÅÅÐò"));
	dict.Insert(make_pair("left", "xxx"));
	dict.Insert(make_pair("insert", "²åÈë"));
	dict.Insert(make_pair("string", "×Ö·û´®"));
	dict.Insert(make_pair("bucket", "Í°"));

	auto dret = dict.Find("left");
	//dret->_kv.first = "xx";
	dret->_kv.second = "×ó±ß";
	dict.Print();

	return 0;
}