#pragma once
#include<iostream>
using namespace std;


template <class K, class V>
struct AVLTreeNode
{

	pair<K, V> _kv;
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		_bf(0)
	{ }
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nulllptr;
		}

		else
		{
			subL->_parent = pParent;

			if (pParent->_left == parent)
				pParent->_left = subL;
			else
				pParent->_right = subL;
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pParent = parent->_parent;

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
			if (pParent->_left == parent)
				pParent->_left = subR;
			else
				pParent->_right = subR;

			subR->_parent = pParent;
		}

		subR->_bf = 0;
		parent->_bf = 0;
	}



	bool Insert(const pair<K, V>& kv)
	{
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
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
			parent->_right = cur;
		else if (parent->_kv.first > kv.first)
			parent->_right = cur;
		
		cur->_parent = parent;

		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				// 旋转
				if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);




				break;
			}
			else
			{
				assert(false);
			}
		}
	}


private:
	Node* _root = nullptr;
};