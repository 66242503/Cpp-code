#pragma once
#include <iostream>
#include <map>
#include <cassert>
#include <algorithm>

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // ƽ������ balance factor

	std::pair<K, V> _kv;

	AVLTreeNode(const std::pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template <class K, class V>

class AVLTree
{
	typedef AVLTreeNode<const K, V> Node;
public:
	AVLTree() = default;

	//t2(t1)
	AVLTree(const AVLTree<K, V>& t)
		:_root(nullptr)
	{
		_root = _Copy(t._root);
	}

	Node* _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newroot = new Node(root->_kv);
		newroot->_bf = root->_bf;
		newroot->_left = _Copy(root->_left);
		newroot->_right = _Copy(root->_right);

		return root;
	}

	~AVLTree()
	{
		_Destory(_root);
		_root = nullptr;
	}

	void _Destory(Node* root)
	{
		if (root == nullptr)
			return;

		_Destory(root->_left);
		_Destory(root->_right);

		delete root;
	}

	bool Insert(const std::pair<K, V>& kv)
	{
		// 1���Ȱ��������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
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
			else if (cur == parent->_left)
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
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						// �Ҹ�����
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
						// ����ҵ���
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				break;
			}
			// ��ת��ɺ�,�߶��Ѿ��ָ�
			// ��������������ϲ���Ӱ�죬���½���
			else
			{
				assert(false);
			}
		}
		return true;
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
		
		// 1.ԭ��parent������������subR�Ǹ�
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		// 2.parentΪ������ֻ�������������������Ҫ�ı����ӹ�ϵ����ôsubRҪ��������λ��
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}

		subR->_bf = parent->_bf = 0;
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
				ppNode->_right = subL;
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		// ��Ӧͼ���ƽ�����ӵ���
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

		RotateL(parent->_left);
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

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
				cur = cur->_right;
			else if (cur->_kv.first > key)
				cur = cur->_left;
			else
				return cur;
		}

		return NULL;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		std::cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		std::cout << std::endl;
	}
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		return std::max(Height(root->_left), Height(root->_right)) + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		return abs(leftHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	// int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.InOrder();

	std::cout << t.IsBalance() << std::endl;
}