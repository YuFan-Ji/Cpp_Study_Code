#pragma once
#include<list>
#include<vector>

namespace jyf
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		//push,top,, pop ,size,empty
		void push(const T& x)
		{
			_con.push_back(x);
		}

		T& top()
		{
			return _con.back();
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_stack()
	{
		//stack<int, vector<int>> st1;
		stack<int> st1;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);

		while (!st1.empty())
		{
			cout << st1.top() << " ";
			st1.pop();
		}
		cout << endl;

		stack<int, list<int>> st2;
		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);

		while (!st2.empty())
		{
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;
	}
}