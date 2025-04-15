#include<iostream>
using namespace std;

//// 使用RAII思想设计的SmartPtr类
//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	ShardPtr<int> sp1(new int);
//	ShardPtr<int> sp2(new int);
//	cout << div() << endl;
//}

#include"SmartPtr.h"

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	~A()
	{
		cout << this;
		cout << " ~A()" << endl;
	}
	//private:

	int _a;
};

//int main()
//{
//	// C++98 一般实践中，很多公司明确规定不要用这个
//	jyf::auto_ptr<A> ap1(new A(1));
//	jyf::auto_ptr<A> ap2(new A(2));
//
//	// 管理权转移，拷贝时，会把被拷贝对象的资源管理权转移给拷贝对象
//	// 隐患：导致被拷贝对象悬空，访问就会出问题
//	//jyf::auto_ptr<A> ap3(ap1);
//
//	// 崩溃
//	//ap1->_a++;
//	//ap3->_a++;
//
//	return 0;
//}

//int main()
//{
//	// C++11  简单粗暴，不让拷贝
//	jyf::unique_ptr<A> up1(new A(1));
//	jyf::unique_ptr<A> up2(new A(2));
//
//	//bit::unique_ptr<A> up3(up1);
//	//up1 = up2;
//
//	return 0;
//}

//int main()
//{
//	// C++11
//	jyf::shared_ptr<A> sp1(new A(1));
//	jyf::shared_ptr<A> sp2(new A(2));
//
//	jyf::shared_ptr<A> sp3(sp1);
//	sp1->_a++;
//	sp3->_a++;
//
//	cout << sp1->_a << endl;
//
//	jyf::shared_ptr<A> sp4(sp2);
//	jyf::shared_ptr<A> sp5(sp4);
//
//	sp1 = sp5;
//	sp3 = sp5;
//
//	jyf::shared_ptr<A> sp6(new A(6));
//	sp6 = sp6;
//	sp4 = sp5;
//
//	// cout << sp6->_a << endl;
//
//	return 0;
//}

struct Node
{
	A _val;

	//jyf::shared_ptr<Node> _next;
	//jyf::shared_ptr<Node> _prev;

	jyf::weak_ptr<Node> _next;
	jyf::weak_ptr<Node> _prev;
	// weak_ptr不是RAII智能指针，专门用来解决shared_ptr循环引用问题
	// weak_ptr不增加引用计数，可以访问资源，不参与资源释放的管理
};

//int main()
//{
//	// 循环引用
//	jyf::shared_ptr<Node> sp1(new Node);
//	jyf::shared_ptr<Node> sp2(new Node);
//
//	sp1->_next = sp2;
//	sp2->_prev = sp1;
//
//
//	return 0;
//}


template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

// 定制删除器
int main()
{
	jyf::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
	jyf::shared_ptr<A> sp2((A*)malloc(sizeof(A)), [](A* ptr) {free(ptr); });
	jyf::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) {
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
		});

	jyf::shared_ptr<A> sp1(new A);

	return 0;
}

