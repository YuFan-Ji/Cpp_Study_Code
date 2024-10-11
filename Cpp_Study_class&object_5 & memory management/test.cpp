//#include<iostream>
//using namespace std;
////class A
//{
//private:
//	static int _k;
//	int _h = 1;
//
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _k << endl;
//			cout << a._h << endl; 
//		}
//	private:
//		int _b;
//	};
//};
//
//int A::_k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	A::B b;
//
//	return 0;
//}


//class Solution {
//	// 内部类
//	class Sum
//	{
//	public:
//		Sum()
//		{
//			_ret += _i;
//			++_i;
//		}
//	};
//	static int _i;
//	static int _ret;
//public:
//	int Sum_Solution(int n) {
//		// 变⻓数组
//		Sum arr[n];
//		return _ret;
//	}
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//
//	Solution() = default;
//private:
//
//};
//
//void func(A aa = A(1))
//{}
//
//int main()
//{
//	A aa1(1);
//	A aa2;
//
//	// 匿名对象，生命周期当前一行
//	A(1);
//	A();
//
//	Solution s1;
//	cout << s1.Sum_Solution(10) << endl;
//
//	cout << Solution().Sum_Solution(10) << endl;
//
//	func();
//
//	const A& r = A();
//
//	return 0;
//}

#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	
//		A & operator=(const A & aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// 传值传参
//	A aa1;
//	//f1(aa1);
//	//cout << endl;
//	//// 隐式类型，连续构造+拷⻉构造->优化为直接构造
//	//f1(1);
//	//// ⼀个表达式中，连续构造+拷⻉构造->优化为⼀个构造
//	//f1(A(2));
//	//cout << endl;
//	//cout << "***********************************************" << endl;
//		 /*传值返回
//		 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019 debug）
//		 ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022 debug）*/
//	//f2();
//	//cout << endl;
//	// 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019 debug）
//	// ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022 debug）
//	A aa2 = f2();
//	cout << endl;
//	// ⼀个表达式中，连续拷⻉构造+赋值重载->⽆法优化
//	/*aa1 = f2();
//	cout << endl;*/
//	return 0;
//}'


//int main()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3];
//	int* ptr7 = new int[3]{ 1,2,3 };
//	int* ptr8 = new int[5]{ 1,2,3 };
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//  delete[] ptr7;
//  delete[] ptr8;
//	return 0;
//}
//
//int main()
//{
//	int* ptr = new int;
//	int* ptr2 = new int(10);
//	int* ptr3 = new int[10];
//	int* ptr4 = new int[3] {1, 2, 3};
//	int* ptr5 = new int[19] {1, 2, 3, 4, 5};
//	delete ptr;
//	delete ptr2;
//	delete[] ptr3;
//	delete[] ptr4;
//	delete[] ptr5;
//}


class A
{
public:
	A(int a = 1)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};

//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
//	//还会调用构造函数和析构函数
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}
//
//int main()
//{
//	A* p1 = new A(1);
//	delete p1;
//	A* p2 = new A[10]{ 1, 2, 3, 4 };
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
// 定位new/replacement new
int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没
	//有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);
	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
	return 0;
}