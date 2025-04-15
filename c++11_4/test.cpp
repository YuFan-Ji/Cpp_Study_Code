#include<iostream>
using namespace std;

//// ʹ��RAII˼����Ƶ�SmartPtr��
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
//		throw invalid_argument("��0����");
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
//	// C++98 һ��ʵ���У��ܶ๫˾��ȷ�涨��Ҫ�����
//	jyf::auto_ptr<A> ap1(new A(1));
//	jyf::auto_ptr<A> ap2(new A(2));
//
//	// ����Ȩת�ƣ�����ʱ����ѱ������������Դ����Ȩת�Ƹ���������
//	// ���������±������������գ����ʾͻ������
//	//jyf::auto_ptr<A> ap3(ap1);
//
//	// ����
//	//ap1->_a++;
//	//ap3->_a++;
//
//	return 0;
//}

//int main()
//{
//	// C++11  �򵥴ֱ������ÿ���
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
	// weak_ptr����RAII����ָ�룬ר���������shared_ptrѭ����������
	// weak_ptr���������ü��������Է�����Դ����������Դ�ͷŵĹ���
};

//int main()
//{
//	// ѭ������
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

// ����ɾ����
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

