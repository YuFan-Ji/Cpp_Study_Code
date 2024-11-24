#pragma once

#include"RBTree.h"

namespace jyf
{
	template<class K, class V>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K,V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const pair<const K,V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K,V>, MapKeyOfT> _t;
	};
}