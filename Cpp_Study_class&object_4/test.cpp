//#include"Date.h"
//
//int main()
//{
//	const Date d1(2024, 8, 10);
//	const Date d2(2004, 2, 5);
//	cout << d1 - d2 << endl;
//	cout << d2 - d1 << endl;
//
//	Date d3(2024, 8, 10);
//	Date d4(2004, 2, 5);
//
//	cout << d3 - d4 << endl;
//
//	cout << &d1 << endl;
//	cout << &d3 << endl;
//
//	//d1 << cout;
//	//d1.operator<<(cout);
//
//	//Date d(2023, 2, 29);
//
//	//cout << d1;
//	//operator<<(cout, d1);
//
//	//cin >> d1 >> d2;
//	//cout << d1 << d2 << endl;
//
//	return 0;
//}

//
#include<iostream>
using namespace std;
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的默认构造，完成了两个成员的初始化
//	// 如果栈没有默认构造
//	MyQueue(int& r, int n = 10)
//		:_pushst(n)
//		,_popst(n+1)
//		,_y(1)
//		,_z(r)
//	{
//		_x = 1;
//	}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//	const int _y;
//	int& _z;
//
//	int _x;
//};
//
//
//int main()
//{
//	int i = 0;
//	// 对象整体
//	MyQueue q1(i);
//	MyQueue q2(i, 100);
//
//	//const int j = 1;
//
//	return 0;
//}
//
//int main()
//{
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 4)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int& x, int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		// error C2512: “Time”: 没有合适的默认构造函数可用
//		// error C2530 : “Date::_ref” : 必须初始化引用
//		// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t; // 没有默认构造
//	int& _ref; // 引用
//	const int _n; // const
//};
//
//int main()
//{
//	int i = 0;
//	Date d1(i);
//	d1.Print();
//	return 0;
//}
/////////////////////////////////////////
//#include <iostream>
//using namespace std;
//
//class Time
//{
//public:
//    Time(int hour)
//        //: _hour(hour)
//    {
//        cout << "Time()" << endl;
//    }
//
//private:
//    int _hour;
//};
//
//class Date
//{
//public:
//    // 使用引用传递时，删除动态分配，避免递归
//    Date(int year = 2, int month = 2, int day =2)
//        : _year(year)
//        , _month(month)
//        //, _day(day)   
//        //, a(ref)     // 引用类型变量必须在初始化列表中初始化
//        //, _n(n)      // const 类型变量必须在初始化列表中初始化
//    {
//        // 构造函数体内无需再初始化这些变量
//    }
//
//    void Print() const
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year = 2;
//    int _month = 2;
//    int _day = 2;
//
//    Time _t;         // 没有默认构造函数的类类型变量
//    //Date& a;         // 引用类型
//    //const int _n;    // const 成员变量
//
//};
//
//
//int main()
//{
//    Date d1;
//    d1.Print();
//    return 0;
//}

//#include<iostream>
//using namespace std;

//class A
//{
//public:
//    // 构造函数，不加 explicit，允许隐式类型转换
//    explicit A(int a1) : _a1(a1) {}
//
//    // 多参数构造函数，同样允许隐式类型转换
//    A(int a1, int a2) : _a1(a1), _a2(a2) {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//
//    int Get() const {
//        return _a1 + _a2;
//    }
//
//private:
//    int _a1 = 1;
//    int _a2 = 2;
//};
//
//class B
//{
//public:
//    // 接受 A 类对象的构造函数
//    B(const A& a) : _b(a.Get()) {}
//
//private:
//    int _b = 0;
//};
//
//int main()
//{
//    // 1. 隐式类型转换：整数 1 被隐式转换为 A 类的对象
//    A aa1 = 1;
//    aa1.Print(); // 输出: 1 2
//
//    // 2. 通过临时对象隐式转换为 A 类的引用
//    const A& aa2 = 1; // 隐式创建一个 A 对象
//
//    // 3. C++11 支持多参数初始化，构造一个包含两个参数的 A 类对象
//    A aa3 = { 2, 2 };
//    aa3.Print(); // 输出: 2 2
//
//    // 4. A 类对象被隐式转换为 B 类对象
//    B b = aa3;
//
//    // 5. A 类对象隐式转换为 B 类对象并绑定为常量引用
//    const B& rb = aa3;
//
//    return 0;
//}


// 实现⼀个类，计算程序中创建出了多少个类对象？
//#include<iostream>
//using namespace std;
//class a
//{
//public:
//	a()
//	{
//		++_scount;
//	}
//	a(const a& t)
//	{
//		++_scount;
//	}
//	~a()
//	{
//		--_scount;
//	}
//    static int getacount()
//	{
//		return _scount;
//	}
//private:
//	// 类⾥⾯声明
//	static int _scount;
//};
//// 类外⾯初始化
//int a::_scount = 0;
//
//void fxx()
//{
//	int ret = a::getacount();
//}
//
//int main()
//{
//	cout << a::getacount() << endl;
//	a a1, a2;
//	a a3(a1);
//	cout << a::getacount() << endl;
//	cout << a1.getacount() << endl;
//	// 编译报错：error c2248: “a::_scount”: ⽆法访问 private 成员(在“a”类中声明)
//	//cout << a::_scount << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//class A
//{
//	// 友元声明
//	friend void func(const A & aa, const B & bb);
//	private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
	// 友元声明
	friend class B;
private:
	int _a1 = 1;
	int _a2 = 2;
};
class B
{
public:
	void func1(const A& aa)
	{
		cout << aa._a1 << endl;
		cout << _b1 << endl;
	}
	void func2(const A& aa)
	{
		cout << aa._a2 << endl;
		cout << _b2 << endl;
	}
private:
	int _b1 = 3;
	int _b2 = 4;
};
int main()
{
	A aa;
	B bb;
	bb.func1(aa);
	bb.func1(aa);
	return 0;
}