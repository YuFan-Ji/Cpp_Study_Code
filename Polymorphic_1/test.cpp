//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

// �麯����д��һЩϸ�ڣ�
// ��д�������������麯��+��ͬ��������һЩ����
// 1�����������д�麯�����Բ���virtual -- �������Ҷ����ϣ�
// 2��Э�䣬���ص�ֵ���Բ�ͬ������Ҫ�󷵻�ֵ�����Ǹ��ӹ�ϵָ�������

//class Person {
//public:
//	virtual	void BuyTicket() const { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() const { cout << "��Ʊ-���" << endl; }
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
//		cout << "��Ʊ-ȫ��" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "��Ʊ-���" << endl;
//		return 0;
//	}
//};
//
////
////class Person {
////public:
////	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
////};

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//		cout << "��Ʊ-ȫ��" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "��Ʊ-���" << endl;
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//// 11:40����
//// ���������������麯����Ϊʲô��Ҫ���麯����
//// ����������virtual���ǲ����麯����д��
//// �ǣ���Ϊ�������������������destructor���ͳһ������
//// ΪʲôҪ��ô�����أ���ΪҪ�����ǹ�����д
//// ��ΪʲôҪ�����ǹ�����д�أ�
//// ��Ϊ����ĳ���
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
//	// ������������p->destructor()��һ����̬���ã���������ͨ����
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//	void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

//
//
//class Person {
//public:
//	virtual	void BuyTicket() const { cout << "��Ʊ-ȫ��" << endl; }
//protected:
//	int _a;
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() const { cout << "��Ʊ-���" << endl; }
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
//	// ���϶�̬������ʱ��ָ�������麯�������ҵ��ú����ĵ�ַ
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
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }

	int _a = 1;
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
	int _b = 1;
};

void Func(Person& p)
{
	// ���϶�̬������ʱ��ָ�������麯�������ҵ��ú����ĵ�ַ
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