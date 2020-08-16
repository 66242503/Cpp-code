#pragma once
#include <iostream>

enum Color
{
	BLACK,
	RED, 
};


template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;

	Color _col;
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		// 1.���������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				cur = cur->_right;
				parent = cur;
			}
			else if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
				parent = cur;
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
		cur->_col = RED;
		while (parent->_col == RED)
		{
			// ���ɫ�������ؼ�������/uncle
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				// ���1�����uncle�����ҽڵ�Ϊ��
				if (uncle && uncle->_col = RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = BLACK;
					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
			}

			else
			{
				// ˫��->��Ϊ����
				if (parent->_parent->_right)
				{
					RotateL(parent);
					std::swap(parent, cur);
				}

				// �ڶ�������������ֱ����
				RotateR(grandfather);
				grandfather->_col = RED;
				parent->_col = BLACK;

				break;
			}
		}

		else
		{
			Node* 
		}
		return true;
	}
private:
	Node* _root = nullptr;
};