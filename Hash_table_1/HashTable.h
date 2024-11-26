#pragma once

#include<vector>

enum STATE
{
	EXIST,     // ����
	EMPTY,     // ��
	DELETE     // ɾ��
};

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	STATE _state = EMPTY;     // ��ʼ״̬Ϊ��
};

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

template<class K, class V, class HashFunc = DefaultHashFunc<K>>
class HashTable
{
public:
	HashTable()
	{
		_table.resize(10);  
	}

	bool Insert(const pair<K, V>& kv)
	{
		// ����
		if ((double)_n / _table.size() >= 0.7)
		{
			size_t newsize = _table.size() * 2;

			// ���½���һ���±�
			HashTable<K, V> newtable;
			newtable._table.resize(newsize);

			// �����ɱ������ݷŵ��±���ȥ
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					newtable.Insert(_table[i]._kv);
				}
			}

			_table.swap(newtable._table);
		}

		// ����̽��
		// �º�������
		HashFunc hf;

		size_t hashi = hf(kv.first) % _table.size();
		while (_table[hashi]._state == EXIST)
		{
			++hashi;
			hashi %= _table.size();
		}

		_table[hashi]._state = EXIST;
		_table[hashi]._kv = kv;
		++_n;

		return true;
	}

	HashData<const K, V>* Find(const K& key)
	{
		// ����̽��
		HashFunc hf;

		size_t hashi = hf(key) % _table.size();
		while (_table[hashi]._state != EMPTY )
		{
			if (_table[hashi]._state == EXIST
				&& _table[hashi]._kv.first == key)
			{
				return (HashData<const K, V>*) & _table[hashi];
			}

			++hashi;
			hashi %= _table.size();
		}

		return nullptr;
	}
	
	bool Erase(const K& key)
	{
		HashData<const K, V>* ret = Find(key);

		if (ret)
		{
			ret->_state = DELETE;
			--_n;
			return true;
		}

		return false;
	}

private:
	vector<HashData<K, V>> _table;
	size_t _n = 0;     // �洢��Ч���ݵĸ���
};