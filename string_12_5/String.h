#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;



class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;


	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const iterator begin() const 
	{
		return _str;
	}

	const iterator end() const
	{
		return _str + _size;
	}
	/*String()
		:_str(new char[1] {'\0'})
		,_size(0)
		,_capacity(0)
	{ }*/

	void swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	

	/*String(const String& str)
	{
		_str = new char[str._capacity + 1];
		strcpy(_str, str._str);
		_size = str._size;
		_capacity = str._capacity;
	}*/
	

	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	/*String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}*/
	String(const char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		// capacity 不包含 '\0'
		_capacity = _size;
		strcpy(_str, str);
	}
	String(const String& str)
	{
		String tmp(str._str);
		swap(tmp);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			// 为什么下面的调用构造函数
			String tmp(s._str);
			// 为什么下面的调用拷贝构造
			String tmp(s);
			swap(tmp);
		}
		return *this;
	}

	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	const char* c_str() const
	{
		return _str;
	}

	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	void reserve(size_t n);
	void push_back(char ch);
	void append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	void insert(size_t pos, char ch);
	void insert(size_t pos, const char* str);
	void erase(size_t pos, size_t len = npos);
	size_t find(char ch, size_t pos = 0);
	size_t find(const char* str, size_t pos = 0);
	String substr(size_t pos, size_t len = npos);
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

bool operator<(const String& s1, const String& s2);
bool operator<=(const String& s1, const String& s2);
bool operator>(const String& s1, const String& s2);
bool operator>=(const String& s1, const String& s2);
bool operator==(const String& s1, const String& s2);
bool operator!=(const String& s1, const String& s2);
ostream& operator<<(ostream& out, String& s);
istream& operator>>(istream& in, String& s);