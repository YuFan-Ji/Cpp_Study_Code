//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

// 虚函数重写的一些细节：
// 重写的条件本来是虚函数+三同，但是有一些例外
// 1、派生类的重写虚函数可以不加virtual -- （建议大家都加上）
// 2、协变，返回的值可以不同，但是要求返回值必须是父子关系指针和引用

//class Person {
//public:
//	virtual	void BuyTicket() const { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() const { cout << "买票-半价" << endl; }
//};
//
//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	virtual	A* BuyTicket() const { 
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "买票-半价" << endl;
//		return 0;
//	}
//};
//
////
////class Person {
////public:
////	virtual void BuyTicket() { cout << "买票-全价" << endl; }
////};

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//	void Func(Person& p)
//	{
//		p.BuyTicket();
//	}
//
//	int main()
//	{
//		Person ps;
//		Student st;
//		Func(ps);
//		Func(st);
//		return 0;
//	}

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	virtual	A* BuyTicket() const { 
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "买票-半价" << endl;
//		return 0;
//	}
//};


//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////////////
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	~Student() {
//		cout << "~Student()" << endl;
//		delete[] ptr;
//	}
//
//protected:
//	int* ptr = new int[10];
//};
//
//// 11:40继续
//// 析构函数可以是虚函数吗？为什么需要是虚函数？
//// 析构函数加virtual，是不是虚函数重写？
//// 是，因为类析构函数都被处理成destructor这个统一的名字
//// 为什么要这么处理呢？因为要让他们构成重写
//// 那为什么要让他们构成重写呢？
//// 因为下面的场景
//
//int main()
//{
//	//Person p;
//	//Student s;
//
//	Person* p = new Person;
//	p->BuyTicket();
//	delete p;
//
//	p = new Student;
//	p->BuyTicket();
//	delete p; // p->destructor() + operator delete(p)
//
//	// 这里我们期望p->destructor()是一个多态调用，而不是普通调用
//
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

//
//
//class Person {
//public:
//	virtual	void BuyTicket() const { cout << "买票-全价" << endl; }
//protected:
//	int _a;
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() const { cout << "买票-半价" << endl; }
//
//	int _b;
//	int* ptr = new int[10];
//};
//
//int main()
//{
//	Person* p = new Student;
//	return 0;
//}

//class A
//{};
//
//class B : public A
//{};
//
//int main()
//{
//	B bb;
//
//	return 0;
//}

//class A
//{
//public:
//	static A CreatAobj()
//	{
//		return A();
//	}
//private:
//	A();
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A aa = A::CreatAobj();
//	//B bb;
//
//	return 0;
//}
#include<iostream>
using namespace std;
//class A
//{
//public:
//	static void Delete(A* aa)
//	{
//		delete aa;
//	}
//private:
//	~A() {};
//};
//
//class B : public A
//{};
//
//int main()
//{
//	A* aa = new A;
//	A::Delete(aa);
//	//B bb;
//	return 0;
//}


//class A final
//{};
//
//class B : public A
//{};
//
//int main()
//{
//	B bb;
//
//	return 0;
//}



//class p
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}
//
//
//	void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	char _b = 1;
//};
//
//void Func(Person& p)
//{
//	// 符合多态，运行时到指向对象的虚函数表中找调用函数的地址
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//	return 0;
//}


class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }

	int _a = 1;
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
	int _b = 1;
};

void Func(Person& p)
{
	// 符合多态，运行时到指向对象的虚函数表中找调用函数的地址
	p.BuyTicket();
}

int main()
{
	Person Mike;
	Func(Mike);

	Student Johnson;
	Func(Johnson);

	return 0;
}