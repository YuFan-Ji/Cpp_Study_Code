#include<iostream>

using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//private:
//	int _age = 18;  // 年龄
//};

//void fun()
//{
//	Person p;
//	p.Print();
//	p._name;
//	p._age;
//}

// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了
// Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
// 以看到变量的复用。调用Print可以看到成员函数的复用。

//class Student : public Person
//{
//protected:
//	int _stuid;  // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int jobbit;  //工号
//};
//
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class student : public Person
//{
//public:
//	void test()
//	{
//		Print();
//		cout << _name << endl;
//		//cout << _age << endl;
//	}
//private:
//	int _stuid = 2300110545;  //学号
//};

//class student : protected Person
//{
//public:
//	void test()
//	{
//		Print();
//		cout << _name << endl;
//		cout << _age << endl;
//	}
//private:
//	int _stuid = 2300110545;  //学号
//};

//class student : private Person
//{
//public:
//	void test()
//	{
//		Print();
//		cout << _name << endl;
//		cout << _age << endl;
//	}
//private:
//	int _stuid = 2300110545;  //学号
//};
//
//int main()
//{
//	student s;
//	s.Print();  //类外调用父类的public的函数
//	s._name;    //类外调用父类的protected内容
//	s._age;     //类外调用父类的private内容
//
//	s.test();   //调用子类自己的函数测试父类中protect与private的内容类内能否访问
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。
//// 这里体现出了Student和Teacher复用了Person的成员。
//// 下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//// 调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	/*int i = 0;
//	double d = i;
//	double& d = i;
//	const double& d = i;*/
//
//	Person p;
//	Student s;
//
//	// 赋值兼容转换(切割，切片)
//	//p = s;
//	Person p1 = s;
//	Person& rp = s;
//	rp._name = "张三";
//
//	Person* ptrp = &s;
//	ptrp->_name = "李四";
//
//	//s = (Student)p;
//
//	return 0;
//}

//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//// 隐藏/重定义：子类和父类有同名成员，子类的成员隐藏了父类的成员
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << "Student::func()" << endl;
//	}
//
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	s.fun();
//	s.Person::fun();
//
//	return 0;
//}

 // 两个fun构成什么关系？
 // a、隐藏/重定义   b、重载   c、重写/覆盖  d、编译报错
 // 答案：a  (父子类域中，成员函数名相同就构成隐藏)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//// 隐藏/重定义：子类和父类有同名成员，子类的成员隐藏了父类的成员
//class Student : public Person
//{
//public:
//	void fun(int i)
//	{
//		cout << "Student::func()" << endl;
//	}
//
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Person::fun();
//	s.fun(1);
//
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "peter") //假设先提供一下默认构造
//	//Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//		//delete _pstr;
//	}
//protected:
//	string _name; // 姓名
//
//	//Person类
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	// 先父后子
//	Student(const char* name = "张三", int id = 0)
//		:Person(name)
//		,_id(0)
//	{}
//
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		// 由于后面多态的原因(具体后面讲)，析构函数的函数名被
//		// 特殊处理了，统一处理成destructor
//
//		// 显示调用父类析构，无法保证先子后父
//		// 所以子类析构函数完成就，自定调用父类析构，这样就保证了先子后父
//
//		Person::~Person();
//		cout << *_pstr << endl;
//
//
//		//delete _ptr;
//	}
//protected:
//	int _id;
//
//	//int* _ptr = new int;
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//
//	Student s3("李四", 1);
//	s1 = s3;
//
//	return 0;
//}


//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}



class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
 string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

int main()
{
	TestPerson();
}