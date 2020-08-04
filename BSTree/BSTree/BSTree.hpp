#pragma once
#include <iostream>

template <class K>
struct BSTreeNode // Binary Searh Tree
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;

	K _key;

	BSTreeNode(const K& key)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{};
};

template<class K>
class BSTree // Binary Searh Tree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
	
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}

			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
			parent->_right = cur;

		else
			parent->_left = cur;
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return true;
		}
		return false;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 开始删除
				// 1.左为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}
					delete cur;
				}
				// 2. 右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
					delete cur;
				}
				// 3. 左右都不为空
				else
				{
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					cur->_key = rightMin->_key;
					if (rightMin == rightMinParent->_left)
						rightMinParent->_left = rightMin->_right;
					else
						rightMinParent->_right = rightMin->_right;
					delete rightMin;
				}
				return true;
			}
		}
		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		std::cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		std::cout << std::endl;
	}



private:
	Node* _root = nullptr;
};

void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 5, 3, 2, 1, 4, 7, 8, 9, 6, 0 };
	for (auto &e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	for (auto &e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}