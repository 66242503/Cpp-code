#pragma once
#include <iostream>
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // 平衡因子 balance factor

	std::pair<K, V> _kv;

	AVLTree(const std::pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
};

template <class K, class V>

class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		// 1、先按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0)
				break;
			// 高度不变，无需调整
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 高度改变向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{

			}
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		
		// 1.原来parent是树根，现在subR是根
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr
		}

		else
		{
			if (ppNode->_left == parent)
				ppNode->_parent = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}
	}
private:
	Node* _root;
};