#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

namespace zzq
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}