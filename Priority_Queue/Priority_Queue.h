#pragma once
#include<vector>

namespace jyf
{
	//�º���ģ��ʵ��/��������
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
		//���µ���
		void AdjustDown(int parent)
		{
			//�º�������һ������������������滻�Ƚ�
			Compare com;

			int child = parent * 2 + 1;

			while (child < _con.size())
			{
				// ����Ҫ�Ŵ���ѣ��������У����Ҫ�Һ����д����һ��
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

		//���ϵ���
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

		//Ĭ�Ϲ��죬�����Զ������ͣ���ȥ��_con�Ĺ��캯��
		priority_queue() {}

		//֧�ֵ�����
		//������ҲҪд��ģ��
		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			//���µ�������
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}

		void push(const T& x)
		{
			//�ȷŵ���β
			_con.push_back(x);
			//�������ϵ���
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			//�Ƚ�����һ�������һ��
			swap(_con[0], _con[_con.size() - 1]);
			//ɾ����β
			_con.pop_back();

			//���µ���
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
		// Ĭ���Ǵ�� -- less
		//priority_queue<int> pq;

		// �º�������ʵ��С��
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

