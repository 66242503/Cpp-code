#pragma once
#include <vector>
#include <iostream>

namespace pri_qu
{
	// 仿函数 函数对象
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};

	template<class T, class Container = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:
		void push(const T& x)
		{
			_c.push_back(x);
			AdjustUp(_c.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;
			std::swap(_c[0], _c[_c.size() - 1]);
			_c.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _c[0];
		}

		size_t size() const
		{
			return _c.size();
		}
		bool empty() const
		{
			return _c.empty();
		}
	private:
		Container _c;
	private:
		void AdjustUp(size_t child)
		{
			compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				// if (_c[child] > _c[parent])
				if (com(_c[parent], _c[child]))
				{
					std::swap(_c[child], _c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(size_t parent)
		{
			size_t child = parent * 2 + 1;
			compare com;
			while (child < _c.size())
			{
				// if (child + 1 < _c.size() && _c[child + 1] > _c[child])
				if (child + 1 < _c.size() && com(_c[child], _c[child + 1]))
				{
					++child;
				}
				// if (_c[child] > _c[parent])
				if (com(_c[parent],_c[child]))
				{
					std::swap(_c[child], _c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	};
}