#include<iostream>
#include<queue>
#include<vector>
#include <functional> // greater�㷨��ͷ�ļ�
using namespace std;

#include"Priority_Queue.h"

void test_priority_queue01()
{

	priority_queue<int> q;
	// Ĭ���Ǵ���ѣ�������ʵʡ��������ģ�������д������������
	// <���ȼ���������, ������, �º���> ������; 
	// priority_queue<int, vector<int>, less<int>> q;
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(1);

	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;

	// ���Ҫ��С���ѣ�Ҳ��������Ҫ�������һ��ģ������º�����Ҳ���Ǹı�Ƚϵķ�ʽ
	priority_queue<int, deque<int>, greater<int>> q2;
	q2.push(2);
	q2.push(3);
	q2.push(4);
	q2.push(1);
	while (!q2.empty())
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;
}

void test_priority_queue02()
{
	vector<int> v = { 1, 3, 5 ,2 ,9 };
	priority_queue<int> q(v.begin(), v.end());
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	
private:
	int _year;
	int _month;
	int _day;
};

void test_priority_queue03()
{
	// ��ѣ���Ҫ�û����Զ����������ṩ<������
	priority_queue<Date> q1;
	q1.push(Date(2024, 10, 27));
	q1.push(Date(2024, 10, 20));
	q1.push(Date(2024, 10, 22));
	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	// ���Ҫ����С�ѣ���Ҫ�û��ṩ>������
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2024, 10, 27));
	q2.push(Date(2024, 10, 20));
	q2.push(Date(2024, 10, 22));
	while (!q2.empty())
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;
}

template<class T>
class LessDate
{
public:
	bool operator()(const Date* pd1, const Date* pd2) const
	{
		// ������ȥ����������ȴ�С
		return *pd1 < *pd2;
	}
};

void test_priority_queue04()
{
	//��ʱ�����Ǿ���Ҫ�Լ��ṩһ������Date*���͵ıȽϷ�ʽ�ˡ�
	priority_queue<Date*, vector<Date*>, LessDate<Date*>> q;
	q.push(new Date(2024, 10, 27));
	q.push(new Date(2024, 10, 20));
	q.push(new Date(2024, 10, 22));

	while (!q.empty())
	{
		cout << *q.top() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	//test_priority_queue01();
	//test_priority_queue02();
	//test_priority_queue03();
	//test_priority_queue04();
	jyf::test_priority_queue1();
	return 0;
}