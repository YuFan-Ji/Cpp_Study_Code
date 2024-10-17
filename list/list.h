#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace jyf
{

	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;

		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator* ()
		{
			return _node->_val;
		}

		Ptr operator-> ()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!= (const self& it)
		{
			return _node != it._node;
		}

		bool operator== (const self& it)
		{
			return _node == it._node;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			//这里做了隐式类型转换
			return _head->_next;
			//也可以写成这样
			//return iterator(head->_next);
		}

		iterator end()
		{
			//这里做了隐式类型转换
			return _head;
			//也可以写成这样
			//return iterator(head);
		}

		const const_iterator begin() const
		{
			return _head->_next;
		}

		const const_iterator end() const
		{
			return _head;
		}


		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(const list<T>& lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		T& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();

			while (it != end())
			{
				it = erase(it);
			}

			_size = 0;
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);

			newnode->_next = head;
			newnode->_prev = head->_prev;
			head->_prev->_next = newnode;
			head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_next = cur;

			cur->_prev = newnode;
			newnode->_prev = prev;

			++_size;

			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			--_size;

			return next;
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};

	void Print(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			// (*it) += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list01()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();

		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto& e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	class A
	{
	public:
		A(int a = 0, int b = 0)
			: _a(a)
			, _b(b)
		{}

		int _a;
		int _b;
	};

	void test_list02()
	{
		list<A> lt;
		lt.push_back(A(1, 1));
		lt.push_back(A(2, 2));
		lt.push_back(A(3, 3));
		lt.push_back(A(4, 4));

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it)._a << " " << (*it)._b << endl;
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_a << " " << it->_b << endl;
			++it;
		}
		cout << endl;


	}

	void test_list03()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(5);
		lt.push_front(6);
		lt.push_front(7);
		lt.push_front(8);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_front();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << lt.size() << endl;
	}

	void test_list04()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt1(lt);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(20);
		lt2.push_back(30);
		lt2.push_back(40);

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1 = lt2;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
