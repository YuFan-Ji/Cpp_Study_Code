#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
namespace bit

{
    class string
    {
        
    public:
        typedef char* iterator;
    public:
        string(const char* str = "");
        string(const string& s);  
        string& operator=(const string& s);

        ~string();
        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        /////////////////////////////////////////////////////////////



        // modify
        void push_back(char c);
        string& operator+=(char c);
        string& operator+=(const char* str);
        void append(const char* str);

        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);

        void clear();

        void swap(string& s);

        const char* c_str()const
        {
            return _str;
        }



        /////////////////////////////////////////////////////////////

        // capacity
        size_t size()const;
        size_t capacity()const;
        bool empty()const;
        void resize(size_t n, char c = '\0');
        void reserve(size_t n);
        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index);
        const char& operator[](size_t index)const;

        /////////////////////////////////////////////////////////////

   

        // ����c��string�е�һ�γ��ֵ�λ��

        size_t find(char c, size_t pos = 0) const;

        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��

        size_t find(const char* s, size_t pos = 0) const;


        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

        string& erase(size_t pos, size_t len);

    private:

        char* _str;

        size_t _capacity;

        size_t _size;

    public:
        static const size_t npos;

    }; 

    //relational operators

   //����Ƚϵ�����
    bool operator== (const string& lhs, const string& rhs);
    bool operator!= (const string& lhs, const string& rhs);
    bool operator> (const string& lhs, const string& rhs);
    bool operator>= (const string& lhs, const string& rhs);
    bool operator< (const string& lhs, const string& rhs);
    bool operator<= (const string& lhs, const string& rhs);

    //�������������룬����ȡ
    ostream& operator<< (ostream& os, const string& str);
    istream& operator>> (istream& is, string& str);

    istream& getline(istream& is, string& str, char delim = '\n');
}