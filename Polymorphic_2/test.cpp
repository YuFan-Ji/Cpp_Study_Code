#include<iostream>
using namespace std;
//
//class A
//{
//public:
//    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//    virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//    void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//
//};
//
//int main(int argc, char* argv[])
//{
//    B* p = new B;
//    p->test();
//    return 0;
//}

//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//private:
//	virtual void Func3()
//	{
//		//_b++;
//		cout << "Student::Func3()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//void test()
//{
//	Person ps1;
//	Student st1;
//}

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void func() { cout << "Person:: func()" << endl; }
//protected:
//	int _a;
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//protected:
//	int _b;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	p = s;
//
//	Person* p = &p;
//
//	Person* p1 = &s;
//	Person& p2 = s;
//	return 0;
//}


//
//class Person
//	{
//	public:
//		virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//		virtual void func() { cout << "Person:: func()" << endl; }
//	protected:
//		int _a;
//	};
//	
//	class Student : public Person
//	{
//	public:
//		virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//		//�Լ����麯��
//		virtual void myself() { cout << "myself" << endl; }
//	protected:
//		int _b;
//	};
//	
//	int main()
//	{
//		Student s;
//		return 0;
//	}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	
//	virtual void Func1() 
//	{
//		cout << "Person::Func1()" << endl;
//	}
//	
//	virtual void Func2() 
//	{
//		cout << "Person::Func2()" << endl;
//	}	
//protected:
//	int _a = 0;
//};
//	
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	
//private:
//	virtual void Func3()
//	{
//		cout << "Student::Func3()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	int a = 0;
//	printf("ջ��%p\n", &a);
//
//	static int b = 0;
//	printf("��̬����%p\n", &b);
//
//	int* p = new int;
//	printf("�ѣ�%p\n", p);
//
//	const char* str = "hello world";
//	printf("��������%p\n", str);
//
//	printf("���1��%p\n", *((int*)&ps));
//	printf("���2��%p\n", *((int*)&st));
//
//	return 0;
//}


class Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }

	virtual void Func1() 
	{
		cout << "Person::Func1()" << endl;
	}

	virtual void Func2() 
	{
		cout << "Person::Func2()" << endl;
	}

protected:
	int _a = 0;
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

private:
	virtual void Func3()
	{
		cout << "Student::Func3()" << endl;
	}
protected:
	int _b = 1;
};

typedef void(*FUNC_PTR)();

void PrintVFT(FUNC_PTR* table)
{
	for (size_t i = 0; table[i] != nullptr; i++)
	{
		printf("[%d]: %p-> ", i, table[i]);

		//����һ�¶�Ӧ�ĺ���
		FUNC_PTR f = table[i];
		f();
	}
	cout << endl;
}

//int main()
//{
//	Person ps;
//	Student st;
//
//	int vft1 = *((int*)&ps);
//	PrintVFT((FUNC_PTR*)vft1);
//
//	int vft2 = *((int*)&st);
//	PrintVFT((FUNC_PTR*)vft2);
//
//	return 0;
//}

//// ��̬��
//// ��̬(����ʱ)�Ķ�̬����������
//// ��̬(����ʱ)�Ķ�̬���̳У��麯����д��ʵ�ֵĶ�̬
//int main()
//{
//	int i = 1;
//	double d = 1.1;
//	cout << i << endl;
//	cout << d << endl;
//
//	Person ps;
//	Person* ptr = &ps;
//
//	ps.BuyTicket();
//	ptr->BuyTicket();
//
//	return 0;
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

//int main()
//{
//	Derive d;
//	//cout << sizeof(d) << endl;
//	int vft1 = *((int*)&d);
//
//	//int vft2 = *((int*)((char*)&d + sizeof(Base1)));
//	Base2* ptr = &d;
//	int vft2 = *((int*)ptr);
//
//	PrintVFT((FUNC_PTR*)vft1);
//	PrintVFT((FUNC_PTR*)vft2);
//}

int main()
{
	Derive d;

	Base1* ptr1 = &d;
	ptr1->func1();

	Base2* ptr2 = &d;
	ptr2->func1();
	return 0;
}