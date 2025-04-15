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

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			//string tmp(s._str);
			//swap(tmp);
		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;

			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		string& operator=(string&& s)
		{
			cout << "string& operator=(string && s) -- �ƶ�����" << endl;
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
		size_t _capacity; // �������������ʶ��\0
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

// ģ��ɱ����
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// ��֧��������
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
//	// ���������ĺ���
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
////args����0-N�Ĳ�����
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
//args����0-N�Ĳ�����
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
		cout << "Date����" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date��������" << endl;
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
//	// emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//	// ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
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
	// ����������һ�´��п���������ƶ������jyf::string����������
	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back
	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
	std::list< std::pair<int, jyf::string> > mylist;
	mylist.emplace_back(10, "sort");
	mylist.push_back(make_pair(30, "sort"));


	std::list<Date> lt;
	Date d(2023, 9, 27);
	// ֻ�ܴ����������
	lt.push_back(d);

	// �����������
	// �����������Ĳ�����
	// ��������һ·���´���ֱ��ȥ������߿�������ڵ������������
	lt.emplace_back(d);
	lt.emplace_back(2023, 9, 27);

	return 0;
}
