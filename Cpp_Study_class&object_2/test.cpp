#include<iostream>
#include<assert.h>
using namespace std;

//class Date
//{
//public:
//	//带参构造
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	
//	//无参构造
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//全缺省构造
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	//Date d1(2024, 10, 1);
//
//	//Date d2;
//
//	Date d3;
//	return 0;
//}

//
//#include<iostream>
//using namespace std;


//typedef int STDataType;
//class Stack
//{
//public:
	//Stack(int n = 4)
	//{
	//	_a = (STDataType*)malloc(sizeof(STDataType) * n);
	//	if (nullptr == _a)
	//	{
	//		perror("malloc申请空间失败");
	//		return;
	//	}
	//	_capacity = n;
	//	_top = 0;
	//}
	// ...
	
//private:
//	STDataType * _a;
//	size_t _capacity;
//	size_t _top;
//};
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	//编译器默认⽣成MyQueue的构造函数调⽤了Stack的构造，完成了两个成员的初始化
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	MyQueue mq;
//	return 0;
//}



// //用之前C版本Stack实现
//bool isValid(const char* s) {
//	ST st;
//	STInit(&st);
//
//	// "[]]"
//	while (*s)
//	{
//		// 左括号入栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			STPush(&st, *s);
//		}
//		else // 右括号取栈顶左括号尝试匹配
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//
//			char top = STTop(&st);
//			STPop(&st);
//
//			// 不匹配
//			if ((top == '(' && *s != ')')
//				|| (top == '{' && *s != '}')
//				|| (top == '[' && *s != ']'))
//			{
//				STDestroy(&st);
//				return false;
//			}
//		}
//		++s;
//	}
//
//	//"["
//
//	// 栈不为空，说明左括号比右括号多，数量不匹配
//	bool ret = STEmpty(&st);
//	STDestroy(&st);
//	return ret;
//}
//
//bool isValid(const char* s) {
//	Stack st;
//
//	// "[]]"
//	while (*s)
//	{
//		// 左括号入栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			//STPush(&st, *s);
//			st.Push(*s);
//		}
//		else // 右括号取栈顶左括号尝试匹配
//		{
//	
//			if (!st.Empty())
//			{
//				return false;
//			}
//
//			char top = st.Top();
//			st.Pop();
//
//			// 不匹配
//			if ((top == '(' && *s != ')')
//				|| (top == '{' && *s != '}')
//				|| (top == '[' && *s != ']'))
//			{
//				return false;
//			}
//		}
//		++s;
//	}
//
//	// 栈不为空，说明左括号比右括号多，数量不匹配
//	return st.Empty();
//}


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
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
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
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class Myqueue
//{
//public:
//	~Myqueue()
//	{
//		cout << "~Myqueue()" << endl;
//		//free(_ptr);
//
//		// 不需要
//		//_pushst.~Stack();
//	}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//	//int* _ptr;
//};
//
//int main()
//{
//	Date d;
//	Stack st;
//
//	Myqueue mq;
//
//	return 0;
//}


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// Date d2(d1);
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 不是拷贝构造，就是一个普通构造
	//Date(Date* p)
	//{
	//	_year = p->_year;
	//	_month = p->_month;
	//	_day = p->_day;
	//}

	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}

	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}

	STDataType Top()
	{
		assert(_top > 0);

		return _a[_top - 1];
	}

	// st2(st1)
	Stack(const Stack& st)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		memcpy(_a, st._a, sizeof(STDataType) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

class MyQueue
{
public:
private:
	Stack pushst;
	Stack popst;
};

Date Func()
{
	Date ret;
	return ret;
}



//int main()
//{
//	Date d1(2024, 8, 9);
//	Date d3(d1);
//	Date d2 = d1;
//
//	Stack st1(10);
//	Stack st2(st1);
//
//	Date d4 = Func();
//	
//
//	/*MyQueue m1;
//	MyQueue m2(m1);*/
//
//	return 0;
//}


//////////////////////////////////////////////////////////////////////
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year
			&& _month < d._month)
		{
			return true;
		}
		else if (_year == d._year
			&& _month == d._month
			&& _day < d._day)
		{
			return true;
		}

		return false;
	}

	int operator-(const Date& d);

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year
			% 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	Date operator+(int day)
	{

	}

private:
	int _year;
	int _month;
	int _day;
};

// 1、提供对应getxxx函数
// 2、友元--后面会讲
// 3、重载为成员函数

//bool operator<(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year 
//		&& x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year 
//		&& x1._month == x2._month
//		&& x1._day < x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}

int main()
{
	Date d1(2024, 8, 9);
	Date d2(2024, 8, 10);

	//bool ret2 = operator<(d1, d2);
	//// 转换成调用对应的运算符重载函数
	//bool ret3 = d1 < d2;

	bool ret2 = d1.operator<(d2);
	// 转换成调用对应的运算符重载函数
	bool ret3 = d1 < d2;
	cout << ret2 << endl;
	cout << ret3 << endl;

	//int n = d1 - d2;
	Date d2 = d1 + 50;

	// 简单
	int i = 0, j = 1;
	bool ret1 = i < j;

	return 0;
}