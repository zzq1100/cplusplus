#include"String.h"

const size_t String::npos = -1;

void String::reserve(size_t n)
{
	if (_capacity < n)
	{
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}

void String::push_back(char ch)
{
	if (_capacity == _size)
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	}
	_str[_size++] = ch;
	_str[_size] = '\0';
}

void String::append(const char* str)
{
	if (strlen(str) + _size > _capacity)
	{
		reserve(strlen(str) + _size > 2 * _capacity ? strlen(str) + _size : 2 * _capacity);
	}
	strcpy(_str + _size, str);
	_size += strlen(str); 
}

String& String::operator+=(char ch)
{
	push_back(ch);
	return *this;
}

String& String::operator+=(const char* str)
{
	append(str);
	return *this;
}

void String::insert(size_t pos, char ch)
{
	assert(pos <= _size);
	if (_capacity == _size)
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	}
	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + 1] = _str[end]; 
	}
	_str[pos] = ch;
	_size++;
}

void String::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (len + _size > _capacity)
	{
		reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
	}
	size_t end = _size + len;
	while (end - len >= pos)
	{
		_str[end] = _str[end - len];
		end--;
	}
	for (int i = 0; i < len; i++)
	{
		_str[pos + i] = str[i];
	}
	_size += len;
}

void String::erase(size_t pos, size_t len)
{
	assert(pos <= _size);
	if (len >= _size - pos)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		while (pos + len <= _size)
		{
			_str[pos++] = _str[pos + len];
		}
		_size -= len;
		_str[_size] = '\0';
	}
}

size_t String::find(char ch, size_t pos)
{
	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == ch)
			return i;
	}
	return npos;
}

size_t String::find(const char* str, size_t pos)
{
	const char* ptr = strstr(_str + pos, str);
	if (ptr == nullptr)
		return npos;
	else
		return ptr - _str;
}

String String::substr(size_t pos, size_t len)
{
	if (len > _size - pos)
		len = _size - pos;
	String sub;
	sub.reserve(len);
	for (int i = 0; i < len; i++)
	{
		sub[i] = _str[pos + i];
	}
	return sub;
}

bool operator<(const String& s1, const String& s2)
{
	return strcmp(s1.c_str(), s2.c_str()) < 0;
}

bool operator<=(const String& s1, const String& s2)
{
	return (s1 < s2) || (s1 == s2);
}

bool operator==(const String& s1, const String& s2)
{
	return strcmp(s1.c_str(), s2.c_str()) == 0;
}

bool operator>(const String& s1, const String& s2)
{
	return !(s1 < s2);
}

bool operator>=(const String& s1, const String& s2)
{
	return (s1 > s2) || (s1 == s2);
}

bool operator!=(const String& s1, const String& s2)
{
	return !(s1 == s2);
}

istream& operator>>(istream& in, String& s)
{
	s.clear();
	char ch;
	ch = in.get();
	while (ch != '\0' || ch != ' ')
	{
		s += ch;
		ch = in.get();
	}
	return in;
}

ostream& operator<<(ostream& out, const String& s)
{
	for (auto ch : s)
	{
		out << ch;
	}
	return out;
}