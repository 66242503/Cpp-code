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
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						// 右高左单旋
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}

				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						// 左高右单旋
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
			}
			// 旋转完成后,高度已经恢复
			// 如果是子树，对上层无影响，更新结束
			break;
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
		// 2.parent为根的树只是整颗树的子树，如果要改变链接关系，那么subR要顶替它的位置
		else
		{
			if (ppNode->_left == parent)
				ppNode->_parent = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_parent = ppNode;
		}
		subL->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		// 对应图理解平衡因子调节
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}

		else if (bf == 0)
		{
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL ->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}

		else if (bf == 0)
		{
			subL->_bf = 0;
			parent->_bf = 0;
			subLR->_bf = 0;
		}
	}

private:
	Node* _root;
};

