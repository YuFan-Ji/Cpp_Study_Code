#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace jyf
{
	class string
	{

	public:
		//typedef char* iterator;
		using iterator = char*;
		using const_iterator = const char*;

		//string();�������
		string(const char* str = "");
		~string();
		string(const string& s);

		//��ͳд��
		//string& operator=(const string& s);

		//�ִ�д��
		string& operator=(string s);

		char operator[](size_t i);
		const char operator[](size_t i) const;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		size_t size() const
		{
			return _size;
		}

		char* c_str() const
		{
			return _str;
		}

		bool empty()const

		{
			return _size == 0;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void resize(size_t newSize, char c = '\0');
		void reserve(size_t n);

		void push_back(char ch);

		void append(const char* str);

		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void earse(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos);
		size_t find(const char* str, size_t pos);

		void swap(string& str);

		string substr(size_t pos, size_t len);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		static const size_t npos;
	};

	//���⽻��
	void swap(string& s1, string& s2);

	//����Ƚϵ�����
	bool operator== (const string& lhs, const string& rhs);
	bool operator!= (const string& lhs, const string& rhs);
	bool operator> (const string & lhs, const string & rhs);
	bool operator>= (const string & lhs, const string & rhs);
	bool operator< (const string& lhs, const string& rhs);
	bool operator<= (const string& lhs, const string& rhs);

	//�������������룬����ȡ
	ostream& operator<< (ostream& os, const string& str);
	istream& operator>> (istream& is, string& str);

	//getline��ȡ�ַ���
	istream& getline(istream& is, string& str, char delim = '\n');
}

