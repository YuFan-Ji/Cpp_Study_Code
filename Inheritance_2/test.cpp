//#include<iostream>
//using namespace std;
//
//
////class Student
////{
////public:
////	int _num; //学号
////	int _age; //年龄
////};
////
////class Teacher
////{
////public:
////	int _id; // 职工编号
////	int _age; //年龄
////};
////
////class Assistant : public Student, public Teacher
////{
////public:
////	string _majorCourse; // 主修课程
////	int _age; //年龄
////};
////
////int main()
////{
////	Assistant as;
////	as.Student::_age = 18;
////	as.Teacher::_age = 30;
////	as._age = 19;
////
////	return 0;
////}
////
////
////class Person
////{
////public:
////	string _name; // 姓名
////};
////
////class Student : public Person
////{
////protected:
////	int _num; //学号
////};
////
////class Teacher : public Person
////{
////protected:
////	int _id; // 职工编号
////};
////
////class Assistant : public Student, public Teacher
////{
////protected:
////	string _majorCourse; // 主修课程
////};
////void Test()
////{
////	// 这样会有二义性无法明确知道访问的是哪一个
////	Assistant a;
////	a._name = "peter";
////	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
////	a.Student::_name = "xxx";
////	a.Teacher::_name = "yyy";
////}
////
////int main()
////{
////	Test();
////}
//
//class A
//{
//public:
//	int _a;
//};
//
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};

//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 0;
//
//	D d1;
//	return 0;
//}

//int main()
//{
//	D d;
//	d._a = 1;
//
//	B b;
//	b._a = 2;
//	b._b = 3;
//
//	B* ptr = &b;
//	ptr->_a++;
//
//	ptr = &d;
//	ptr->_a++;
//
//	return 0;
//}

//class A
//{
//public:
//	int _a[128];
//};
//
// class B : public A
////class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : public A
////class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//
//
//int main()
//{
//	D d;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	cout << sizeof(D) << endl;
//
//	return 0;
//}

//class Base1 { public:  int _b1; };
//class Base2 { public:  int _b2; };
//class Derive : public Base2, public Base1 { public: int _d; };
//
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

#include<iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};

class B :virtual public A
{
public:
	B(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
};

class C :virtual public A
{
public:
	C(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
};

class D :public B, public C
{
public:
	D(const char* sa, const char* sb, const char* sc, const char* sd) 
		:B(sa, sb), C(sa, sc), A(sa)
	{
		cout << sd << endl;
	}
};

int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;

	return 0;
}