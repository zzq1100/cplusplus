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

	bool Find(const k& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	bool Erase(const k& key)
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
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					
					delete cur;
					return true;
				}
				else
				{
					Node* replace = cur->_right;
					Node* replaceparent = cur;

					while (replace->_left)
					{
						replaceparent = replace;
						replace = replace->_left;
					}

					cur->_key = replace->_key;

					if (replaceparent->_left == replace)
					{
						replaceparent->_left = replace->_right;
					}
					else
					{
						replaceparent->_right = replace->_right;
					}

					delete replace;
					return true;
				}
			}
		}
		return false;
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