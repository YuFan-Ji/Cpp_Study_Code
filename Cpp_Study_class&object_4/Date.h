//#pragma once
//#include<iostream>
//#include<assert.h>
//using namespace std;
//class Date
//{
//	//ÓÑÔªÉùÃ÷
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	int GetMonthDay(int year, int month)const;
//
//	void Print()const;
//
//	Date(int year = 1999, int month = 1, int day = 1);
//
//	bool CheckDate()const;
//
//	bool operator<(const Date& d)const;
//	bool operator>(const Date& d)const;
//	bool operator<=(const Date& d)const;
//	bool operator>=(const Date& d)const;
//	bool operator==(const Date& d)const;
//	bool operator!=(const Date& d)const;
//
//	Date& operator+=(int day);
//	Date operator+(int day)const;
//
//	Date& operator-=(int day);
//	Date operator-(int day)const;
//
//	// ++d1
//	Date& operator++();
//	// d1++
//	Date operator++(int);
//
//	// --d1
//	Date& operator--();
//	// d1--
//	Date operator--(int);
//
//	//d1 - d2
//	int operator-(const Date& d) const;
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d);
//istream& operator>>(istream& in, Date& d);
