#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include<assert.h>
#include<list>
namespace jyf
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(const char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			//string tmp(s._str);
			//swap(tmp);
		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;

			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		string& operator=(string&& s)
		{
			cout << "string& operator=(string && s) -- 移动拷贝" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	//Person(Person&& p) = default;
//	//Person(const Person& p) = default;
//
//private:
//	jyf::string _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//
//	return 0;
//}

// 模板可变参数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// 不支持这样完
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << endl;
//	}
//}

//void ShowList()
//{
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T val, Args... args)
//{
//	cout << val << " ";
//	ShowList(args...);
//}

//void _ShowList()
//{
//	// 结束条件的函数
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void _ShowList(T val, Args... args)
//{
//	cout << val << " ";
//	_ShowList(args...);
//}
//
////args代表0-N的参数包
//template <class ...Args>
//void CppPrint(Args... args)
//{
//	_ShowList(args...);
//}
//
//int main()
//{
//	CppPrint();
//	CppPrint(1);
//	CppPrint(1, 2);
//	CppPrint(1, 2, 2.2);
//	CppPrint(1, 2, 2.2, string("xxxx"));
//
//	// ...
//
//	return 0;
//}

//void CppPrint()
//{
//	cout << endl;
//}
//
//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//
//	return 0;
//}
//
//args代表0-N的参数包
//template <class ...Args>
//void CppPrint(Args... args)
//{
//	int a[] = { PrintArg(args)...};
//	cout << endl;
//}
//
//int main()
//{
//	CppPrint();
//	CppPrint(1);
//	CppPrint(1, 2);
//	CppPrint(1, 2, 2.2);
//	CppPrint(1, 2, 2.2, string("xxxx"));
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date构造" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date拷贝构造" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
//
//
//template <class ...Args>
//Date* Create(Args... args)
//{
//	Date* ret = new Date(args...);
//
//	return ret;
//}
//
//int main()
//{
//	Date* p1 = Create();
//	Date* p2 = Create(2023);
//	Date* p3 = Create(2023, 9);
//	Date* p4 = Create(2023, 9, 27);
//
//	Date d(2023, 1, 1);
//	Date* p5 = Create(d);
//
//
//
//	return 0;
//}


//int main()
//{
//	list< std::pair<int, char> > mylist;
//
//	// emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//	// 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//
//	return 0;
//}

int main()
{
	// 下面我们试一下带有拷贝构造和移动构造的jyf::string，再试试呢
	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
	// 是先构造，再移动构造，其实也还好。
	std::list< std::pair<int, jyf::string> > mylist;
	mylist.emplace_back(10, "sort");
	mylist.push_back(make_pair(30, "sort"));


	std::list<Date> lt;
	Date d(2023, 9, 27);
	// 只能传日期类对象
	lt.push_back(d);

	// 传日期类对象
	// 传日期类对象的参数包
	// 参数包，一路往下传，直接去构造或者拷贝构造节点中日期类对象
	lt.emplace_back(d);
	lt.emplace_back(2023, 9, 27);

	return 0;
}
