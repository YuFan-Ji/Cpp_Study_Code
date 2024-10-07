#include<iostream>
#include<assert.h>
#include"test.h"

using namespace std;

//void Stack1::Init(int n = 4)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc申请空间失败");
//		return;
//	}
//	capacity = n;
//	top = 0;
//}


class Date3
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
	
	_day = day;
	}
private:
	// 为了区分成员变量，⼀般习惯上成员变量
	// 会加⼀个特殊标识，如_ 或者 m开头
	int _year; // year_ m_year
	int _month;
	int _day;
};

class Date2
{
	void DateInit(int year = 2024, int month = 10, int day = 1)
	{
		year = year;//?究竟哪个是形参，哪个是成员变量，傻傻分不清~
		month = month;
		day = day;
	}

	int year;
	int month;
	int day;
};


class Person
{
public:        //公有的接口
	void Init(string name, int age, int phoneNumber)
	{
		_name = name;
		_age = age;
		_phoneNumber = phoneNumber;
	}

private:
	//私有的成员变量
	string _name;
	int _age;
	int _phoneNumber;
};

//int main()
//{
//	Person ps;
//	ps.Init("张三", 28, 10086);
//
//	ps._name = "李四";
//
//	return 0;
//}


//
//#include<iostream>
// using namespace std;
 class Stack
 {
 public:
     // 成员函数
     void Init(int n = 4);

 private:
	// 成员变量
	int* array;
	size_t capacity;
	size_t top;
	//size_t 是在 <stddef.h> 或 <cstddef> 头文件中定义的。
	//它的实际类型由编译器决定，通常是 unsigned int、unsigned long 
	//或其他适合于表示内存大小的无符号整数类型。
 };
// 声明和定义分离，需要指定类域
void Stack::Init(int n)
{
	array = (int*)malloc(sizeof(int) * n);
	if (nullptr == array)
	{
		perror("malloc申请空间失败");
		return;
	}
	capacity = n;
	top = 0;
}
//int main()
//{
//	Stack st;
//	st.Init();
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 这⾥只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.Init(2024, 10, 1);
//	d2.Init(2003, 7, 8);
//}
//
//
//#include<iostream>
//using namespace std;
// 计算⼀下A/B/C实例化的对象是多⼤？
class A
{
public:
	void Print()
	{
		cout << _ch << endl;
	}
private:
	char _ch;
	int _i;
};
class B
{
public:
	void Print()
	{
		//...
	}
};
class C
{};
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//
//}




class Date
{
public:
	void Init(int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2;
	d1.Init(2024, 10, 1);
	d2.Init(2003, 7, 8);
	
	d1.Print();
	d2.Print();
}


//C语言实现：




#include <iostream>
#include <assert.h>

typedef int DataType;

typedef struct Stack

{
	DataType* array;
	int capacity;
	int size;
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 3);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	} ps->capacity = 3;
	ps->size = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}

void CheckCapacity(Stack* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		DataType* temp = (DataType*)realloc(ps->array,

			newcapacity * sizeof(DataType));
		if (temp == NULL)
		{
			perror("realloc申请空间失败!!!");
			return;
		}
		ps->array = temp;
		ps->capacity = newcapacity;
	}
}

void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}

DataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];

}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackDestroy(&s);
	return 0;
}
//C++实现

#include <iostream>
typedef int DataType;

class Stack

{

public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	} void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}
	DataType Top() { return _array[_size - 1]; }
	int Empty() { return 0 == _size; }
	int Size() { return _size; }
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity *

				sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc申请空间失败!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}

private:
	DataType* _array;
	int _capacity;
	int _size;
};

int main()
{
	Stack s;
	s.Init();


	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Pop();
	s.Pop();
	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Destroy();
	return 0;
}