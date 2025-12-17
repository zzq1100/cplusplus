#pragma once
#include<iostream>
using namespace std;


namespace zzq
{
	template <class T>
	struct list_node
	{
		list_node(const T& data = T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{ }
		
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
	
	template <class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		
		list_iterator(Node* node)
			:_node(node)
		{ }
		T& operator*() { return _node->_data; }

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self& s) { return _node != s._node; }

		bool operator==(const Self& s) { return _node == s._node; }
		
		Node* _node;
	};
	
	template <class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T> iterator;

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		
		iterator begin()
		{
			iterator it = _head->_next;
			return it;
			//return _head->_next;
		}

		iterator end() { return _head; }

		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			newnode->_prev = tail;
			newnode->_next = _head;
			tail->_next = newnode;
			_head->_prev = newnode;

			_size++;
		}

		size_t size() { return _size; }

		bool empty() { return _size == 0; }

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			
			newnode->_next = cur;
			newnode->_prev = prev;
			cur->_prev = newnode;
			prev->_next = newnode;

			++_size;
		}

		/*void push_back(const T& x)
		{
			insert(begin(), x);
		}*/

		void push_front(const T& x) { insert(_head->_next, x); }

		void erase(iterator pos)
		{
			Node* next = pos._node->_next;
			Node* prev = pos._node->_prev;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
		}

		void pop_back() { erase(--end()); }

		void pop_front() { erase(begin()); }
	private:
		Node* _head;
		size_t _size = 0;
	};

	void test()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		l.erase(l.begin());
		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}