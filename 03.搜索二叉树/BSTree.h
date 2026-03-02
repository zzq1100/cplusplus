#pragma once

#include<iostream>
using namespace std;

template<class k>
struct BSTreeNode
{
	BSTreeNode(const k& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{ }

	k _key;
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;
};

template<class k>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	bool Insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
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
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};