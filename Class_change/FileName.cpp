
#include<iostream>

using namespace std;


//class A
//{
//public:
//	//explicit A(int a)
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(const A& a)
//	{}
//private:
//	//...
//};

//void insert(size_t pos, char ch)
//{
//	int end = 10;
//	while (end >= pos)
//	{
//		cout << end << endl;
//		//...
//		--end;
//	}
//}

//int main()
//{
//    int i = 1;
//    // 隐式类型转换
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    A aa1 = 1;
//    B bb1 = aa1;
//
//    int* p = &i;
//    // 显示的强制类型转换
//    int address = (int)p;
//
//    printf("%p, %d\n", p, address);
//
//    //vector<int> v;
//    //string s;
//    //v = (vector<int>)s;
//
//    insert(3, 'x');
//    insert(0, 'x');
//
//
//    return 0;
//}

//int main()
//{
//	// volatile 修饰的变量，每次都要去内存取
//	volatile const int n = 10;
//	//n = 11;
//	// 转换有安全隐患的
//	int* p = (int*)&n;
//	(*p)++;
//
//	cout << n << endl;
//	cout << *p << endl;
//
//	cout << p << endl;
//
//	return 0;
//}

//int main()
//{
//	// 相关类型/相近类型
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// 不相关类型
//	int* p1 = &a;
//	int address = reinterpret_cast<int>(p1);
//
//	// 去掉const属性
//	volatile const int n = 10;
//	int* p2 = const_cast<int*>(&n);
//
//	// 
//
//
//	return 0;
//}

class A
{
public:
	virtual void f() {}

	int _x = 0;
};

class B : public A
{
public:
	int _y = 0;
};

void fun(A* pa)
{
	// pa是指向子类对象B的，转换可以成功，正常返回地址
	// pa是指向父类对象A的，转换失败，返回空指针
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		cout << "转换成功" << endl;
		pb->_x++;
		pb->_y++;
	}
	else
	{
		cout << "转换失败" << endl;
	}
}


int main()
{
	A aa;
	fun(&aa);

	B bb;
	fun(&bb);

	return 0;
}