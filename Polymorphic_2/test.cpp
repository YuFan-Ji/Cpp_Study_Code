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
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void func() { cout << "Person:: func()" << endl; }
//protected:
//	int _a;
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//		virtual void BuyTicket() { cout << "买票-全价" << endl; }
//		virtual void func() { cout << "Person:: func()" << endl; }
//	protected:
//		int _a;
//	};
//	
//	class Student : public Person
//	{
//	public:
//		virtual void BuyTicket() { cout << "买票-半价" << endl; }
//		//自己的虚函数
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
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
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//	printf("栈：%p\n", &a);
//
//	static int b = 0;
//	printf("静态区：%p\n", &b);
//
//	int* p = new int;
//	printf("堆：%p\n", p);
//
//	const char* str = "hello world";
//	printf("常量区：%p\n", str);
//
//	printf("虚表1：%p\n", *((int*)&ps));
//	printf("虚表2：%p\n", *((int*)&st));
//
//	return 0;
//}


class Person
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }

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
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

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

		//调用一下对应的函数
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

//// 多态：
//// 静态(编译时)的多态，函数重载
//// 动态(运行时)的多态，继承，虚函数重写，实现的多态
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