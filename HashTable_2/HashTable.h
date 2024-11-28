#pragma once
#include<vector>

namespace hash_bucket
{
	template<class K>
	struct DefaultHashFunc
	{
		size_t operator() (const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct DefaultHashFunc<string>
	{
		size_t operator() (const string& str)
		{
			// BKDR
			size_t hash = 0;
			for (auto ch : str)
			{
				hash *= 131;
				hash += ch;
			}

			return hash;
		}
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		HashData<K, V>* _next;

		HashData(const pair<K, V>& kv)
			: _kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashData<K, V> Node;
	public:
		HashTable()
		{
			_table.resize(10, nullptr);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// 仿函数控制
			HashFunc hf;

			// 如果需要扩容
			if (_n == _table.size())
			{
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				// 遍历旧表，顺手牵羊，把节点牵下来挂到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 头插到新表
						size_t newhashi = hf(cur->_kv.first) % newSize;
						cur->_next = newTable[newhashi];
						newTable[newhashi] = cur;

						cur = next;
					}

					_table[i] = nullptr;
				}

				_table.swap(newTable);
			}

			// 如果不需要扩容
			size_t hashi = hf(kv.first) % _table.size();

			// 头插
			Node* newnode = new Node(kv);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			HashFunc hf;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		void Print()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				printf("[%d]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				printf("NULL\n");
			}
			cout << endl;
			
		}

	private:
		vector<Node*> _table;     // 指针数组
		size_t _n = 0;            // 存储了多少个有效数据
	};
}