#pragma once

#include<vector>

enum STATE
{
	EXIST,     // 存在
	EMPTY,     // 空
	DELETE     // 删除
};

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	STATE _state = EMPTY;     // 初始状态为空
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
		// 扩容
		if ((double)_n / _table.size() >= 0.7)
		{
			size_t newsize = _table.size() * 2;

			// 重新建立一个新表
			HashTable<K, V> newtable;
			newtable._table.resize(newsize);

			// 遍历旧表，将数据放到新表中去
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					newtable.Insert(_table[i]._kv);
				}
			}

			_table.swap(newtable._table);
		}

		// 线形探测
		// 仿函数控制
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
		// 线性探测
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
	size_t _n = 0;     // 存储有效数据的个数
};