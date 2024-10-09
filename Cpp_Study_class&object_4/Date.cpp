//#include"Date.h"
//
//int Date::GetMonthDay(int year, int month)const
//{
//	assert(month > 0 && month < 13);
//	static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		return 29;
//	return arr[month];
//}
//
//void Date::Print()const
//{
//	cout << _year << "��" << _month << "��" << _day << "��" << endl;
//}
//
//bool Date::CheckDate()const
//{
//	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
//		return false;
//	else
//		return true;
//}
//
//Date::Date(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//
//	if (!CheckDate())
//	{
//		cout << "���ڷǷ� -> ";
//		cout << *this;
//	}
//}
//
//bool Date::operator<(const Date& d) const
//{
//	if (_year < d._year)
//	{
//		return true;
//	}
//	else if (_year == d._year
//		&& _month < d._month)
//	{
//		return true;
//	}
//	else if (_year == d._year
//		&& _month == d._month
//		&& _day < d._day)
//	{
//		return true;
//	}
//	return false;
//}
//
//bool Date::operator>(const Date& d)const
//{
//	return !(*this <= d);
//}
//
//bool Date::operator<=(const Date& d)const
//{
//	return *this < d || *this == d;
//}
//
//bool Date::operator>=(const Date& d)const
//{
//	return !(*this < d);
//}
//
//bool Date::operator==(const Date& d)const
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//
//bool Date::operator!=(const Date& d)const
//{
//	return !(*this == d);
//}
//
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= -day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (_month == 13)
//		{
//			_month = 1;
//			_year++;
//		}
//	}
//	return *this;
//}
//
//Date Date::operator+(int day)const
//{
//	Date tmp = *this;
//	tmp += day;
//	return tmp;
//}
//
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this += -day;
//	}
//	_day -= day;
//	while (_day <= 0)
//	{
//		_month--;
//		if (_month == 0)
//		{
//			_month = 12;
//			_year--;
//		}
//		_day += GetMonthDay(_year, _month);
//	}
//	return *this;
//}
//
//Date Date::operator-(int day)const
//{
//	Date tmp = *this;
//	tmp -= day;
//	return tmp;
//}
//
//// ++d1
//Date& Date::operator++()
//{
//	*this += 1;
//	return *this;
//}
//
//// d1++
//Date Date::operator++(int)
//{
//	Date tmp = *this;
//	*this += 1;
//	return tmp;
//}
//
//// --d1
//Date& Date::operator--()
//{
//	*this -= 1;
//	return *this;
//}
//
//// d1--
//Date Date::operator--(int)
//{
//
//	Date tmp = *this;
//	*this -= 1;
//	return tmp;
//}
//
////d1 - d2
//int Date::operator-(const Date& d) const
//{
//	int flag = 1;
//	Date min = d;
//	Date max = *this;
//
//	if (*this < d)
//	{
//		max = d;
//		min = *this;
//		flag = -1;
//	}
//
//	int count = 0;
//	while (min != max)
//	{
//		++min;
//		++count;
//	}
//
//	return count * flag;
//}
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	while (1)
//	{
//		cout << "�������꣬�£��գ�";
//		in >> d._year >> d._month >> d._day;
//		if (d.CheckDate())
//		{
//			break;
//		}
//		else
//		{
//			cout << "���ڷǷ�������������" << endl;
//		}
//	}
//
//	return in;
//}