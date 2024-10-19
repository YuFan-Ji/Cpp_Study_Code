#pragma once
#include<list>
#include<vector>

namespace jyf
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		//push,top,, pop ,size,empty
		void push(const T& x)
		{
			_con.push_back(x);
		}

		T& front()
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		void pop()
		{
			_con.pop_front();
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

	void test_queue()
	{
		queue<int, list<int>> q;

		//queue<int, vector<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}