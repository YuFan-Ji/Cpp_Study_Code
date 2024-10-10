#include"Date.h"

// ��ȡĳ��ĳ�µ�����

int Date::GetMonthDay(int year, int month)
{
	static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	return arr[month];
}

// ȫȱʡ�Ĺ��캯��

Date:: Date (int year, int month , int day)
{
	_year = year;
	_month = month;
	_day = day;
}


// �������캯��

// d2(d1)

Date::Date (const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// ��ֵ���������

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// ��������

Date::~Date()
{

}
// ����+=����

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}

	}
	return *this;
}

// ����+����

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

// ����-����

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

// ����-=����

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{

		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

// ǰ��++

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ����++

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

// --d1
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// d1--
Date Date::operator--(int)
{

	Date tmp = *this;
	*this -= 1;
	return tmp;
}

// >���������

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	return false;
}

// ==���������

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

// >=���������

bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

// <���������

bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=���������

bool Date::operator <= (const Date& d)
{
	return *this < d || *this == d;
}

// !=���������

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// ����-���� ��������

int Date::operator-(const Date& d)
{
	Date min = d;
	Date max = *this;
	int flag = 1;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}

	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}
	return count * flag;
}