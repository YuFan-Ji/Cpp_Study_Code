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
//	string _name = "peter"; // ����
//private:
//	int _age = 18;  // ����
//};

//void fun()
//{
//	Person p;
//	p.Print();
//	p._name;
//	p._age;
//}

// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���
// Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿�
// �Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�

//class Student : public Person
//{
//protected:
//	int _stuid;  // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int jobbit;  //����
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
//	int _stuid = 2300110545;  //ѧ��
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
//	int _stuid = 2300110545;  //ѧ��
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
//	int _stuid = 2300110545;  //ѧ��
//};
//
//int main()
//{
//	student s;
//	s.Print();  //������ø����public�ĺ���
//	s._name;    //������ø����protected����
//	s._age;     //������ø����private����
//
//	s.test();   //���������Լ��ĺ������Ը�����protect��private�����������ܷ����
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
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡�
//// �������ֳ���Student��Teacher������Person�ĳ�Ա��
//// ��������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
//// ����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
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
//	// ��ֵ����ת��(�и��Ƭ)
//	//p = s;
//	Person p1 = s;
//	Person& rp = s;
//	rp._name = "����";
//
//	Person* ptrp = &s;
//	ptrp->_name = "����";
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
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//// ����/�ض��壺����͸�����ͬ����Ա������ĳ�Ա�����˸���ĳ�Ա
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
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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

 // ����fun����ʲô��ϵ��
 // a������/�ض���   b������   c����д/����  d�����뱨��
 // �𰸣�a  (���������У���Ա��������ͬ�͹�������)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//// ����/�ض��壺����͸�����ͬ����Ա������ĳ�Ա�����˸���ĳ�Ա
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
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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
//	Person(const char* name = "peter") //�������ṩһ��Ĭ�Ϲ���
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
//	string _name; // ����
//
//	//Person��
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	// �ȸ�����
//	Student(const char* name = "����", int id = 0)
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
//		// ���ں����̬��ԭ��(������潲)�����������ĺ�������
//		// ���⴦���ˣ�ͳһ�����destructor
//
//		// ��ʾ���ø����������޷���֤���Ӻ�
//		// ������������������ɾͣ��Զ����ø��������������ͱ�֤�����Ӻ�
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
//	Student s3("����", 1);
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
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
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
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
 string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

int main()
{
	TestPerson();
}