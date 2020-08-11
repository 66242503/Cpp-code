#pragma once
#include <iostream>
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // ƽ������ balance factor

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
		// 1���Ȱ��������Ĺ�����в���
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
		// ����ƽ������
		while (parent)
		{
			if (cur == parent->_right)
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0)
				break;
			// �߶Ȳ��䣬�������
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// �߶ȸı����ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{

			}
		}
	}

private:
	Node* _root;
};