#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<assert.h>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}



//int main()
//{
//	int x1{ 1 };
//	int arr1[]{ 1, 2 ,3, 4, 5 };
//	int arr2[5]{ 0 };
//	Point p{ 1 , 2 };
//	// C++11中列表初始化也可以适用于new表达式中
//	int* pa = new int[4] { 0 };
//	Point* pa2 = new Point{ 1 ,2 };
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}

//#include<vector>
//
//struct point
//{
//	int _x;
//	int _y;
//};
//
//void func(initializer_list<int> il)
//{
//	for (auto e : il)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
//
//int main()
//{
//	vector<int> v = { 1 ,2, 3, 4, 5 };
//	//point p = { 1 ,2 };
//	func({ 1, 2, 3, 4, 5 });
//
//	auto il = { 1, 2, 3 ,4 ,5, 6 };
//	cout << typeid(il).name() << endl;
//}

//int main()
//{
//	auto il = { 1, 2, 3 ,4 ,5, 6 };
//	cout << typeid(il).name() << endl;
//}

// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	//const int x = 1;
//	//double y = 2.2;
//	//decltype(x * y) ret; // ret的类型是double
//	//decltype(&x) p;      // p的类型是int*
//
//	//cout << typeid(ret).name() << endl;
//	//cout << typeid(p).name() << endl;
//	//F(1, 'a');
//	//return 0;
//
//	auto il = { 1 ,2, 3, 4, 5 };
//	for (auto e : il)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}


int fmin(int a, int b)
{
	return a < b ? a : b;
}

//int main()
//{
//	//const int a = 10;
//	//int b = a;
//	////a = 20;
//
//	// 以下的ptr、b、c、*p都是左值
//	int* ptr = new int(0);
//	int b = 1;
//	const int c = 2;
//	"xxxxx";
//	const char* p = "xxxxx";
//	p[2];
//
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	// cout << &10 << endl;
//	// cout << &(x+y)<< endl;
//	// cout << &(fmin(x, y)) << endl;
//	cout << &("xxxxx") << endl;
//	cout << &p[2] << endl;
//
//	return 0;
//}

//// 左值引用  右值引用
//// 引用是取别名
//// 左值引用:给左值取别名
//// 右值引用:给右值取别名
//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 左值引用:给左值取别名
//	int a = 0;
//	int& r1 = a;
//
//	// 左值引用能否给右值取别名？
//	// const左值引用可以
//	const int& r2 = 10;
//	const double& r3 = x + y;
//
//	//int& y1 = 10;
//
//	// 右值引用:给右值取别名
//	int&& r5 = 10;
//	double&& r6 = x + y;
//
//	// 右值引用能否给左值取别名？
//	// 右值引用可以引用move以后的左值
//	int&& r7 = move(a);
//
//	return 0;
//}

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
			//cout << "string(char* str)" << endl;

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

			string tmp(s._str);
			swap(tmp);
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

jyf::string func()
{
	jyf::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//cin >> str;
	//....

	return str;
}

//int main()
//{
//	//jyf::string ret1 = func();
//
//	jyf::string ret2;
//	//...
//	ret2 = func();
//
//	return 0;
//}

// //是否构成函数重载 -- 是
//void func(const int& r)
//{
//	cout << "void func(const int& r)" << endl;
//}
//
//void func(int&& r)
//{
//	cout << "void func(int&& r)" << endl;
//}
//
//
//
//int main()
//{
//	int a = 0;
//	int b = 1;
//	func(a);
//
//	// 走更匹配的，有右值引用的重载，就会走右值引用版本
//	func(a + b);
//
//	return 0;
//}

//template<typename T>
//void PerfectForward(T&& t)
//{
//
//}

//int main()
//{
//	jyf::string str1 = "xxxxxxxxxxxxxxxxxxxxx";
//	//jyf::string copy1(str1);
//	//jyf::string copy2 = move(str1);
//
//	cout << endl;
//
//
//	list<jyf::string> v;
//	v.push_back(str1);
//	cout << endl;
//	v.push_back(move(str1));
//	cout << endl;
//	v.push_back("xxxxxxxxxxxxxxxx");
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	jyf::string str1 = "xxxxxxxxxxxxx";
//	jyf::string copy1;
//	move(str1);
//	copy1 = str1;
//	jyf::string copy2 = move(str1);
//
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//// 万能引用：既可以接收左值，又可以接收右值
//// 实参左值，他就是左值引用（引用折叠）
//// 实参右值，他就是右值引用
//template<typename T>
//void PerfectForward(T&& t)
//{
//	// 完美转发，t是左值引用，保持左值属性
//	// 完美转发，t是右值引用，保持右值属性
//	Fun(forward<T>(t));
//	
//}
//
//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//
//	return 0;
//}



struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

//struct ComparePriceLess
struct Compare1
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

//struct ComparePriceGreater
struct Compare2
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

struct CompareEvaluateGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._evaluate > gr._evaluate;
	}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//
//	sort(v.begin(), v.end(), Compare1()); 
//	sort(v.begin(), v.end(), Compare2());
//
//	return 0;
//}

int main()
{
	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };

	auto goodsPriceLess = [](const Goods& x, const Goods& y){return x._price < y._price; };
	cout << goodsPriceLess(v[0], v[1]) << endl;
	sort(v.begin(), v.end(), goodsPriceLess);

	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
		return x._price < y._price; });

	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
		return x._price > y._price;});

	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
		return x._evaluate < y._evaluate;});

	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
		return x._evaluate > y._evaluate;});

	return 0;
}

//auto less = [](int x, int y)->bool {return x < y; };
//cout << less(1, 2) << endl;

//void func()
//{
//	cout << "func()" << endl;
//}

//int main()
//{
//	int a = 0, b = 2;
//	double rate = 2.555;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	auto add2 = [](int x, int y) {return x + y; };
//
//	auto add3 = [rate](int x, int y) {return (x + y)* rate; };
//
//	cout << add1(a, b) << endl;
//	cout << add2(a, b) << endl;
//	cout << add3(a, b) << endl;
//
//
//	auto swap1 = [add1](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//
//		cout << add1(x, y) << endl;
//		func();
//	};
//	swap1(a, b);
//
//
//	return 0;
//}

//int main()
//{
//	int x = 0, y = 2;
//	auto swap1 = [x, y]() mutable {
//	// mutable让捕捉的x和y可以改变了，
//	// 但是他们依旧是外面x和y的拷贝
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1();
//
//	// 引用的方式捕捉
//	auto swap2 = [&x, &y](){
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap2();
//
//	int a = 0;
//	int b = 1;
//	int c = 2;
//	int d = 3;
//	const int e = 1;
//	cout << &e << endl;
//
//	// 引用的方式捕捉所有对象，除了a
//	// a用传值的方式捕捉
//	auto func = [&, a] {
//		//a++;
//		b++;
//		c++;
//		d++;
//		//e++;
//		cout << &e << endl;
//	};
//
//	func();
//
//	return 0;
//}

int main()
{
	auto f1 = [](int x, int y) {return x + y; };
	auto f2 = [](int x, int y) {return x + y; };

	//f1 = f2;
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

	f1(1, 2);


	return 0;
}