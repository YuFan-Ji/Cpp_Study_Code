
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
//    // ��ʽ����ת��
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    A aa1 = 1;
//    B bb1 = aa1;
//
//    int* p = &i;
//    // ��ʾ��ǿ������ת��
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
//	// volatile ���εı�����ÿ�ζ�Ҫȥ�ڴ�ȡ
//	volatile const int n = 10;
//	//n = 11;
//	// ת���а�ȫ������
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
//	// �������/�������
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ���������
//	int* p1 = &a;
//	int address = reinterpret_cast<int>(p1);
//
//	// ȥ��const����
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
	// pa��ָ���������B�ģ�ת�����Գɹ����������ص�ַ
	// pa��ָ�������A�ģ�ת��ʧ�ܣ����ؿ�ָ��
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		cout << "ת���ɹ�" << endl;
		pb->_x++;
		pb->_y++;
	}
	else
	{
		cout << "ת��ʧ��" << endl;
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