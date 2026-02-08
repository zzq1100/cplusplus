#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//template <class T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_arr(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//	~Stack()
//	{
//		delete[] _arr;
//		_arr = nullptr;
//		_size = _capacity = 0;
//	}
//	void Push(const T& x)
//	{
//		if (_size == _capacity)
//		{
//			T* tmp = new T[_capacity * 2];
//			memcpy(tmp, _arr, sizeof(T) * _size);
//			delete[] _arr;
//			_arr = tmp;
//			_capacity *= 2;
//		}
//		_arr[_size++] = x;
//	}
//private:
//	T* _arr;
//	int _size;
//	int _capacity;
//};
//
//
//int main()
//{
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack<double> st2;
//	st2.Push(1.1);
//	st2.Push(2.2);
//
//	return 0;
//}


//template <typename T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_arr(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//
//	~Stack()
//	{
//		delete[] _arr;
//		_arr = nullptr;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& x)
//	{
//		if (_size == _capacity)
//		{
//			T* tmp = new T[_capacity * 2];
//			memcpy(tmp, _arr, sizeof(T) * _size);
//			delete[] _arr;
//			_arr = tmp;
//			_capacity *= 2;
//		}
//		_arr[_size++] = x;
//	}
//private:
//	T* _arr;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack<double> st2;
//	st2.Push(1.1);
//	st2.Push(2.2);
//
//	return 0;
//}


#include<string>
int main()
{
	string s1;
	string s2 = "Hello World";
	/*cout << s1 << s2 << endl;*/

	/*s2[1] = 'z';
	s2[10] = 'z';*/
	/*cout << s2 << endl;*/

	/*string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	

	for (auto ch : s2)
	{
		cout << ch << " ";
	}
	cout << endl;*/



	/*string::iterator it = s2.begin();
	while (it != s2.end())
	{
		*it -= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << s2 << endl;


	for (auto& ch : s2)
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;
	cout << s2 << endl;

	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;*/

	/*for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto ch : s2)
	{
		cout << ch << " ";
	}
	cout << endl;*/






	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto ch : s2)
	{
		cout << ch << " ";
	}
	cout << endl;
	return 0;
}