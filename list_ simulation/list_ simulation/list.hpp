#pragma once

#include <iostream>
#include <assert.h>

namespace ls
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{};
	};

	// __list_iterator<T, T&, T*> iterator
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		// *it
		Ref& operator*()
		{
			return _node->_data;
		}

		Ptr* operator->()
		{
			return &_node->_data;
		}

		//++it;
		Self& operator++()
		{
			_node = _node->_next;
			return  *this;
		}

		// it++
		Self operator++(int)
		{
			Self tmp(*this);
			//_node = _node->_next;
			++(*this);
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator--(int)
		{
			__list_iterator<T> tmp(*this);
			//_node = _node->_prev;
			--(*this);
			return *this;
		}

		// it != end()
		bool operator !=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator ==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		// 带头双向循环链表
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			/*
			const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}
			*/
			for (auto &e : lt)
				push_back(e);
		}

		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto &e : lt)
					push_back(e);
			}
			return *this;
		}

		list<T>& operator=(list<T>& lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
				erase(it++);
		}

		void push_back(const T& x)
		{
			/*
			node* tail = _head->_prev;
			node* newnode = new node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			*/
			insert(end(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void erase(iterator pos)
		{
			assert(pos != end());
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			cur = nullptr;
		}
	private:
		node* _head;
	};
}