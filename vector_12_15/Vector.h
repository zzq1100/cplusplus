#pragma once
#include<iostream>
using namespace std;

namespace zzq
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());

				delete[] _start;
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_end_of_storage == _finish)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		T& operator[] (size_t i)
		{
			return _start[i];
		}

		void pop_back()
		{
			--_finish;
		}


	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	template <class T>
	void print_vector(const vector<T>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	
	

	void test01()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		print_vector(v1);

		vector<double> v2;
		v2.push_back(1.1);
		v2.push_back(2.1);
		v2.push_back(3.1);
		v2.push_back(4.1);
		v2.push_back(5.1);
		v2.push_back(6.1);
		print_vector(v2);
	}
}