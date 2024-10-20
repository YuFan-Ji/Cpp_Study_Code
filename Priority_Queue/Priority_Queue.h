#pragma once
#include<vector>

namespace jyf
{
	//仿函数模拟实现/函数对象
	template<class T>
	class Less
	{
	public:
		bool operator() (const T& a, const T& b)
		{
			return a < b;
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator() (const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		//向下调整
		void AdjustDown(int parent)
		{
			//仿函数定义一个对象出来，用它来替换比较
			Compare com;

			int child = parent * 2 + 1;

			while (child < _con.size())
			{
				// 我们要排大根堆，降序排列，因此要找孩子中大的那一个
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;

				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		//向上调整
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);

					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

	public:

		//默认构造，对于自定义类型，会去调_con的构造函数
		priority_queue() {}

		//支持迭代器
		//迭代器也要写成模板
		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			//向下调整建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}

		void push(const T& x)
		{
			//先放到堆尾
			_con.push_back(x);
			//进行向上调整
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			//先交换第一个和最后一个
			swap(_con[0], _con[_con.size() - 1]);
			//删除堆尾
			_con.pop_back();

			//向下调整
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
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

	void test_priority_queue1()
	{
		// 默认是大堆 -- less
		//priority_queue<int> pq;

		// 仿函数控制实现小堆
		priority_queue<int, vector<int>, Greater<int>> pq;

		pq.push(3);
		pq.push(5);
		pq.push(1);
		pq.push(4);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}

