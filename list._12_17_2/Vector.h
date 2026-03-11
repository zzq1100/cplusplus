#pragma once
#include<iostream>
using namespace std;

namespace zzq
{
	template<class T>
	struct list_node
	{
		list_node(const T& data = T())
			:_data(data)
			,_prev(nullptr)
			,_next(nullptr)
		{ }
		
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;
	};

	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> self;

		list_iterator(Node* node)
			:_node(node)
		{ }

		T& operator*() { return _node->_data; }

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const self& s) { return _node != s._node; }

		bool operator==(const self& s) { return _node == s._node; }
		Node* _node;
	};

	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T> iterator;
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		iterator begin() { return _head->_next; }

		iterator end() { return _head; }

		size_t size() { return _size; }

		void insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;

			++_size;
		}

		void erase(iterator pos)
		{
			Node* prev = pos._node->prev;
			Node* next = pos._node->next;
			prev->_next = next;
			next->_prev = prev;
			delete pos;
			--_size;
		}

		void push_back(const T& x) { insert(end(), x); }

		void push_front(const T& x) { insert(begin(), x); }

		void pop_back() { erase(--end()); }

		void pop_front() { erase(begin()); }


	private:
		Node* _head;
		size_t _size;
	};

	void test()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}