#include<list>
#include<vector>
#include<algorithm>

void test01()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_front(30);
	lt.push_front(88);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_back();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test02()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//list的空间不是连续的，+5 并不能找到list中第5个位置，这样写编译器会报错的
	//lt.insert(lt.begin() + 5, 10);

	list<int>::iterator it = lt.begin();
	
	while (it != lt.end())
	{
		it++;
	}

	lt.insert(it, 89);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//对于insert，迭代器不会失效，因为插入数据list不牵扯扩容，it所指向的逻辑位置也不发生改变
	//库里的没找到会返回last的位置

	it = find(lt.begin(), lt.end(), 3);
	if (it != lt.end())
	{
		lt.insert(it, 30);

		// insert以后，it不失效
		*it *= 100;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//但是对于erase，使用过后迭代器会失效
	it = find(lt.begin(), lt.end(), 2);
	if (it != lt.end())
	{
		lt.erase(it);

		// erase以后，it失效，她的空间已经没了，就是一个野指针
		//*it *= 100;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//要解决这个问题，可以拿iterator做返回值接收，更新it的值
	it = lt.begin();
	
	//还是我们的老朋友，删除list中偶数
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			//就是这里
			it = lt.erase(it);
		}
		else
			it++;

	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test03()
{
	list<int> lt;
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);

	//库中的sort不可以，因为库中的排序是快排，迭代器的种类是随机，而这里迭代器的种类是双向
	//sort(lt.begin(), lt.end());

	//因此库中提供了一种底层为归并排序的排序
	lt.sort();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//list中还有类似逆置，交换这样的，库中和这里的都可以用
	reverse(lt.begin(), lt.end());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 5000000;
	vector<int> v;
	v.reserve(N);
	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt2.push_back(e);
		lt1.push_back(e);
	}

	// 拷贝到vector排序，排完以后再拷贝回来
	int begin1 = clock();
	// 先拷贝到vector
	for (auto e : lt1)
	{
		v.push_back(e);
	}

	// 排序
	sort(v.begin(), v.end());

	// 拷贝回去
	size_t i = 0;
	for (auto& e : lt1)
	{
		e = v[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

void test04()
{
	int myints[] = { 17,89,7,14 };
	/*std::list<int> mylist(myints, myints + 4);

	//remove是删除特定的值，找到了就删除，没找到就什么也不干
	mylist.remove(890);

	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl*/;

	//unique是去重，一般要先排序，这要去重效率高
	//mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	//// 15.3,  72.25, 72.25, 73.0,  73.35

	//mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	//// 15.3,  72.25, 73.0,  73.35



	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	it = mylist1.begin();
	++it;                         // points to 2

	//转移是从iterator的位置，转移另一个list （整个/第i个位置/一个迭代区间）
	// 全部转移
	mylist1.splice(it, mylist2);

	// 部分转移
	//mylist1.splice(it, mylist2, ++mylist2.begin());
	//mylist1.splice(it, mylist2, ++mylist2.begin(), mylist2.end());

	//转移自己
	//mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin(), mylist1.end());

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include"list.h"

int main()
{
	//用法测试：
	
	//test01();
	//test02();
	//test03();
	//test_op();
	//test04();

	//模拟实现测试
	//jyf::test_list01();
	//jyf::test_list02();
	//jyf::test_list03();
	jyf::test_list04();
	return 0;
}