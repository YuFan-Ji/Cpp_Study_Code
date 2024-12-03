#pragma once
#include<vector>
#include <string>


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

	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			: _data(data)
			, _next(nullptr)
		{}
	};

	// ǰ������
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;

		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// ��ǰͰ��û��
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				// ����һ��λ�ò��Ҳ�����һ����Ϊ�յ�Ͱ
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
					{
						++hashi;
					}
				}

				_node = nullptr;
			}

			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		// ��Ԫ����
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, T, T&, T*, KeyOfT, HashFunc> iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyOfT, HashFunc> const_iterator;

		iterator begin()
		{
			// �ҵ�һ��Ͱ
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			// �ҵ�һ��Ͱ
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}

			return const_iterator(nullptr, this);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

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

		bool Insert(const T& data)
		{
			// �º�������
			KeyOfT kot;

			if (Find(kot(data)))
			{
				return false;
			}

			// �º�������
			HashFunc hf;

			// �����Ҫ����
			if (_n == _table.size())
			{
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				// �����ɱ�˳��ǣ�򣬰ѽڵ�ǣ�����ҵ��±�
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;

						// ͷ�嵽�±�
						size_t newhashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[newhashi];
						newTable[newhashi] = cur;

						cur = next;
					}

					_table[i] = nullptr;
				}

				_table.swap(newTable);
			}

			// �������Ҫ����
			size_t hashi = hf(kot(data)) % _table.size();

			// ͷ��
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
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
			KeyOfT kot;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (kot(cur->_data) == key)
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
			KeyOfT kot;

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
		vector<Node*> _table;     // ָ������
		size_t _n = 0;            // �洢�˶��ٸ���Ч����
	};
}