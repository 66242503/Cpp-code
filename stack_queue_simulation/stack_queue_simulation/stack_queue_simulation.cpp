#pragma once

#include <list>
#include <iostream>
#include <vector>

namespace st
{

	template <class T, class Container>

	class stack
	{
	public:
		void push(const T& x){ _c.push_back(x); }
		void pop(){ _c.pop_back(); }
		size_t size() { return _c.size(); }
		bool empty(){ return _c.empty(); }
		T& top(){ return _c.back(); }
	private:
		Container _c;
	};
}


namespace que
{
	template <class T, class Container>
	class queue
	{
	public:
		void push(const T& x){ _c.push_back(x); }
		void pop(){ _c.pop_front(); }
		size_t size() { return _c.size(); }
		bool empty(){ return _c.empty(); }
		T& front(){ return _c.front(); }
		T& back(){ return _c.back(); }
	private:
		Container _c;
	};
}