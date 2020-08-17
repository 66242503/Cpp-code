#pragma once
#include "RBTree.hpp"

namespace my_map
{
	template<class K, class V>

	class map
	{
		struct MapkeyOfT
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, std::pair<K, V>, MapkeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		bool Insert(const std::pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, std::pair<K, V>, MapkeyOfT> _t;
	};

	using namespace std;
	void test_map()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(3, 3));
		m.Insert(make_pair(10, 10));
		m.Insert(make_pair(5, 5));
		m.Insert(make_pair(6, 6));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto kv : m)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

		cout << endl;
	}
}