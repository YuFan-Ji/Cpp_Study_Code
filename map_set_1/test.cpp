#include<iostream>
#include<map>
#include<set>

using namespace std;

void test_set01()
{
	//// 排序 + 去重
	//set<int> s;
	//s.insert(3);
	//s.insert(5);
	//s.insert(2);
	//s.insert(1);
	//s.insert(7); s.insert(7); s.insert(7); s.insert(7);
	//s.insert(8);
	//
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////s.erase(3);
	////s.erase(100);
	////for (auto e : s)
	////{
	////	cout << e << " ";
	////}
	////cout << endl;

	//if (s.find(5) != s.end()) 
	//	cout << "找到啦！" << endl;

	//if (s.count(5))
	//	cout << "找到啦！" << endl;

	//set<int> myset;
	//for (int i = 1; i < 9; i++)
	//	myset.insert(i * 10);

	//// myset：10 20 30 40 50 60 70 80
	//std::set<int>::iterator itlow, itup;
	// 对于itlow与itup形成的区间是：
	// [itlow, itup)
	// 对于lower_bound查找的是 >= x 的迭代器
	// 对于upper_bound查找的是 > x 的迭代器
	/*itlow = myset.lower_bound(30);  
	itup = myset.upper_bound(70);

	cout << " itlow: " << *itlow 
		 << "      itup: " << *itup << endl;
	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}
	cout << endl;*/

	// myset：10 20 30 40 50 60 70 80
	/*itlow = myset.lower_bound(35);
	itup = myset.upper_bound(90);


	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}
	cout << endl;*/



	//////////////////
	set<int> myset;
	for (int i = 1; i < 9; i++)
		myset.insert(i * 10);

	// myset：10 20 30 40 50 60 70 80
	std::set<int>::iterator itlow, itup;
	//std::pair<set<int>::const_iterator, const set<int>::const_iterator> ret = myset.equal_range(70);
	// 这里可以用auto简写
	auto ret = myset.equal_range(70);
	itlow = ret.first;
	itup = ret.second;
	
	cout << *itlow << endl;
	cout << *itup << endl;
}

void test_set02()
{
	/*multiset<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(7); s.insert(7); s.insert(7); s.insert(7);
	s.insert(8);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "7的个数为: " << s.count(7) << endl;*/

	multiset<int> myset;
	for (int i = 1; i < 9; i++)
		myset.insert(i * 10);
	myset.insert(70); myset.insert(70); myset.insert(70);
	// myset：10 20 30 40 50 60 70 70 70 70 80
	std::multiset<int>::iterator itlow, itup;
	
	auto ret = myset.equal_range(70);
	itlow = ret.first;
	itup = ret.second;

	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}
	cout << endl;
}

int main()
{
	//test_set01();
	//test_set02();

	set<int> s;
	s.insert(1); s.insert(2); s.insert(3);
	auto it = s.begin();
	*it = 10;
	return 0;
}