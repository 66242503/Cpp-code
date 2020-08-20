#pragma once

#include "HashTable.h"
using namespace OPEN_HASH;

namespace my_unorderdr_set
{
	template<class K, class Hash = OPEN_HASH::_Hash<K>>
	class unordered_set
	{
	private:
		struct SetKOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename HashTable<K, K, SetKOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
		std::pair<iterator, bool> insert(const K& k)
		{
			return _ht.Insert(k);
		}
	private:
		HashTable<K, K, SetKOfT, Hash> _ht;
	};
	
	void test_unordered_set()
	{
		unordered_set<int> s;
		s.insert(1);
		s.insert(5);
		s.insert(4);
		s.insert(2);

		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
}