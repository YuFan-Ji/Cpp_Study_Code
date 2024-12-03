#pragma once
#include"HashTable.h"

namespace jyf
{
	template<class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
		 
		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;
	};
}