#pragma once
#include<iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template <typename K, typename V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{ }
};

template <typename K, typename V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* grandfather = parent->_parent;
	
		subL->_right = parent;
		parent->_parent = subL;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (_root == parent)
		{
			subL = _root;
			subL->_parent = nullptr;
		}
		else
		{
			subL->_parent = grandfather;
			if (grandfather->_left == parent)
				grandfather->_left = subL;
			else
				grandfather->_right = subL;
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* grandfather = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (parent == _root)
		{
			subR = _root;
			subR->_parent = nullptr;
		}
		else
		{
			subR->_parent = grandfather;
			if (grandfather->_left == parent)
				grandfather->_left = subR;
			else
				grandfather->_right = subR;
		}

	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
			parent->_right = cur;
		else 
			parent->_left = cur;

		cur->_parent = parent;	

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			Node* uncle = nullptr;
			if (grandfather->_left == parent)
			{
				uncle = grandfather->_right;

				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
	
			}
			else
			{
				uncle = grandfather->_left;

				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
				
			}
			
			
		}

		_root->_col = BLACK;

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
		cout << root->_kv.first << " " << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};