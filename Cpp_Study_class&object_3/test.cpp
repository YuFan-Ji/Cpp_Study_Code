//#include<iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// d1 == d2 -> d1.operator=(d2)
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	Date operator+=(int day)
//	{
//
//	}
//
//	// ++d1;
//	// d1.operator++()
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	// d1++
//	// d1.operator++(1)
//	Date operator++(int i)
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(A::*PF)();
//
////int operator+(int x, int y)
////{
////	return x - y;
////}
////
////int main()
////{
////
////	//void(A::*pf)();
////	//PF pf = &A::func;
////	//A obj;
////	//// 对象调用成员函数指针时，使用.*运算符
////	//(obj.*pf)();
////
////	Date d1(2024, 7, 5);
////	Date d2(2024, 7, 6);
////
////	// 运算符重载函数可以显示调用
////	//d1.operator==(d2);
////
////	// 编译器会转换成 d1.operator==(d2);
////	//d1 == d2;
////
////	/*d1++;
////	++d1;*/
////
////	return 0;
////}
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	 d2 = d3;
//	 d2.operator=(d3)
//	 d1 = d1;
//	/*Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 8, 10);
//	// 拷贝构造用于一个已经存在对象拷贝初始化给另一个要创建的对象。
//	Date d2(d1);
//	Date d4 = d1;
//	Date d3(2024, 9, 11);
//
//	// 用于完成两个已经存在的对象直接的拷贝赋值
//	//d1 = d3;
//	//d1.operator=(d3);
//	d1 = d2 = d3;
//	d1 = d1;
//
//	int i, j, k;
//	i = j = k = 1;
//
//	return 0;
//}
//
//
//int main()
//{
//
//
//	return 0;
//}

///////////////////////////////////////////////////

#include"Date.h"


//int main()
//{
//	Date d1(2024, 8, 10);
//	d1.Print();
//
//	//Date d2(d1 + 100);
//	Date d2 = d1 + 100;
//	d2.Print();
//	d1.Print();
//
//	d1 += 100;
//	d1.Print();
//
//	int i = 1;
//	i += 100;
//
//	d1 -= 100;
//	d1.Print();
//
//	cout << endl;
//
//	Date d3(2024, 8, 10);
//	d3.Print();
//	d3 += 7000;
//	d3.Print();
//
//	return 0;
//}

//int main()
//{
//	Date d1(2024, 8, 10);
//	d1.Print();
//
//	d1 += 100;
//	d1.Print();
//
//	d1 += -100;
//	d1.Print();
//
//	Date ret1 = ++d1;
//	d1.Print();
//
//	Date ret2 = d1++;
//	d1.Print();
//
//	ret1.Print();
//	ret2.Print();
//
//	return 0;
//}


int main()
{
	Date d1(2024, 10, 2);
	Date d2(2024, 10, 19);

	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;

	//d1 << cout;
	//d1.operator<<(cout);

	Date d(2023, 2, 29);

	cout << d1;
	operator<<(cout, d1);

	cin >> d1 >> d2;
	cout << d1 << d2 << endl;



	return 0;
}