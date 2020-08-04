#pragma once

#include <iostream>
#include <string>

template <class K, class V>

struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key, const V& value)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _value(value)
	{}
};

template<class K, class V>
class BSTree // Binary Searh Tree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);
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

		cur = new Node(key, value);
		if (parent->_key < key)
			parent->_right = cur;

		else
			parent->_left = cur;
		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return cur;
		}
		return nullptr;
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
		std::cout << root->_key << " : " << root->_value << std::endl;
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
	BSTree<std::string, std::string> dict;
	dict.Insert("search", "搜索");
	dict.Insert("exist", "存在");
	dict.Insert("attribute", "属性");
	dict.Insert("construct", "创造");
	dict.Insert("container", "容器");
	dict.InOrder();

	//std::string str;
	//while (std::cin >> str)
	//{
	//	BSTreeNode<std::string, std::string>* ret = dict.Find(str);
	//	if (ret)
	//		std::cout << ret->_value << std::endl;

	//	else
	//		std::cout << "查无此词" << std::endl;
	//}

	std::string strs[] = { "苹果", "苹果", "西瓜", "桃子", "香蕉", "梨" ,"樱桃"};
	BSTree<std::string, int> fruits;
	for (auto &str : strs)
	{
		BSTreeNode<std::string, int>* ret = fruits.Find(str);
		if (ret == nullptr)
		{
			fruits.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	fruits.InOrder();
}