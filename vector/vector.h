#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

namespace jyf
{
	template<class T>
	class vector
	{
	public:
		//���������
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		//�������
		//�޲�Ĭ�Ϲ���
		vector()
		{}

		//����Ϊn��val
		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		//��һ�ε����������ʼ��
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//C++11֧��{ }��ʼ������ʽinitializer_list
		vector(initializer_list<T> il)
		{
			//��ǰ���ռ䣬��߲���Ч�ʣ���СƵ�����ռ�
			reserve(il.size());

			for (auto& e : il)
			{
				push_back(e);
			}
		}

		//��������
		vector(const vector<T>& v)
		{
			//��ͳд��
			_start = new T[v.capacity()];

			//memcpy��ǳ��������������Դ���������Ͳ�����
			//memcpy(_start, v._start, sizeof(T) * v.size());

			//���
			for (int i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();

			// �ִ�д��
			/*vector<T> tmp(v);
			swap(tmp);*/
		}

		//��ͳд��Ҳ����������ȥ����
		/*vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}*/


		//��ֵ����
		vector<T>& operator= (vector<T> v)
		{
			//�ִ�д��
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;

				_start = _finish = _endofstorage = 0;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//operator[]
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		//��ȡsize
		size_t size() const
		{
			return _finish - _start;
		}

		//��ȡcapacity
		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		//�п�
		bool empty() const
		{
			return _start == _finish;
		}

		//Ԥ���ռ�
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];

				if (_start)
				{
					//memcpyֻ��ǳ����
					//memcpy(tmp, _start, sizeof(T) * oldsize);
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}

		//�ı�size��С
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		//β��
		void push_back(T x)
		{
			/*if (size() == capacity())
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = x;
			_finish++;*/

			insert(_finish, x);
		}

		//βɾ
		void pop_back()
		{
			/*assert(!empty());
			--_finish;*/
			erase(--_finish);
		}

		//����λ�ò���
		iterator insert(iterator pos, T x)
		{
			assert(pos >= _start && pos <= _finish);

			if (size() == capacity())
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}

			iterator i = _finish - 1;
			while (i >= pos)
			{
				*(i + 1) = *i;
				--i;
			}

			*pos= x;
			_finish++;

			return pos;
		}

		//ɾ������λ�õ�ֵ
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator i = pos + 1;
			while (i != _finish)
			{
				*(i - 1) = *i;
				++i;
			}
			--_finish;

			return pos;
		}

	private:

		iterator _start = nullptr;               //��ͷλ��
		iterator _finish = nullptr;              //size��С����λ����һ��
		iterator _endofstorage = nullptr;        //capacity��һ��λ��
	};

	void printf(const vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}

		cout << endl;
	}

	void test01()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		cout << "size = " << v1.size() << endl;
		cout << "capacity = " << v1.capacity() << endl;
		v1.push_back(5);
		cout << "size = " << v1.size() << endl;
		cout << "capacity = " << v1.capacity() << endl;

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e <<" ";
		}
		cout << endl;

		cout << "//////////////////////////////////" << endl;

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		cout << "size = " << v1.size() << endl;
		cout << "capacity = " << v1.capacity() << endl;

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
		//v1.pop_back();

		cout << "//////////////////////////////////" << endl;

		vector<int>:: iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
	}

	void test02()
	{
		/*vector<int> v1;
		v1.insert(v1.begin(), 1);
		v1.insert(v1.begin(), 2);
		v1.insert(v1.begin(), 3);
		v1.insert(v1.begin() + 2, 4);
		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;*/
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.insert(v1.begin() + 2, 30);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2 = { 1,2,3,4,5,6 };
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test03()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		/*v1.erase(v1.begin()+4);*/
		auto pos = v1.begin();
		v1.erase(pos);
		//// erase�Ժ󣬵�����ʧЧ�ˣ����ܷ���
		//// vs����ǿ�Ƽ�飬���ʻ�ֱ�ӱ���
		//vs2022�����Ż�����������
		cout << *pos << endl;
		++pos;
		cout << *pos << endl;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test04()
	{
		///////////��ȥvecter<int>�е�ż��///////////
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
				// ����ô���գ���Щ�������ᱨ��,vs2022���˴���
				it = v1.erase(it);
			else
				++it;
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test05()
	{
		vector<int> v;
		v.resize(10, 0);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test06()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int> v1(v);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2;
		v2.resize(10, 1);

		v1 = v2;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test07()
	{
		vector<string> v;
		v.push_back("111111111111111111");
		v.push_back("222222222222222222");
		v.push_back("333333333333333333");
		v.push_back("444444444444444444");
		v.push_back("555555555555555555");

		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<string> v1(v);
		for (auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test08()
	{
		vector<string> v1 = { "123456", "456789", "asdasdasd" };
		for (auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test09()
	{
		vector<int> v(10u, 1);
		//vector<string> v1(10, "1111");

		vector<int> v2(10, 1);



		// vector<int> v;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;


		/*vector<int> v3(v.begin(), v.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;

		string str("hello world");
		vector<char> v4(str.begin(), str.end());
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;

		int a[] = { 16,2,77,29 };
		vector<int> v5(a, a + 4);
		for (auto e : v5)
		{
			cout << e << " ";
		}
		cout << endl;*/
	
	}

}