#pragma once
#include<iostream>
using namespace std;

namespace zzq
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
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

        // construct and destroy

        vector()
        { }

        vector(int n, const T& value = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                push_back(value);
            }
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }
        
        vector(const vector<T>& v)
        {
            reserve(v.size());
            for (auto& e : v)
            {
                push_back(e);
            }
        }

        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

            // capacity

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                T* tmp = new T[n];
                memcpy(tmp, _start, sizeof(T) * size());

                delete[] _start;
                _start = tmp;
                _finish = _start + size();
                _end_of_storage = _start + capacity();
            }
        }

        void resize(size_t n, const T& value = T())
        {
            if (n < capacity)
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while (_finish != _start + n)
                {
                    *_finish = value;
                    ++_finish;
                }
            }
        }

        T& operator[](size_t pos)
        {
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            return _start[pos];
        }

        void push_back(const T& x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish == x;
            ++_finish;
        }

        void pop_back()
        {
            --_finish;
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        iterator insert(iterator pos, const T& x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            iterator end = _finish - 1;
            while (pos <= end)
            {
                _start[end + 1] = _start[end];
                --end;
            }
            _start[pos] = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos)
        {
            iterator end = pos;
            while (end < _finish)
            {
                _start[end] = _start[end + 1];
                ++end;
            }
            --_finish;
        }

        
    private:

        iterator _start = nullptr; // 指向数据块的开始
        iterator _finish = nullptr; // 指向有效数据的尾
        iterator _end_of_storage = nullptr; // 指向存储容量的尾
    };
    
    template<class T>
    void print(const vector<T>& x)
    {
        auto it = x.begin();
        while (it != x.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        /*for (auto e : x)
        {
            cout << x << " ";
        }
        cout << endl;*/
    }

    void test()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(1);
        v1.push_back(1);
        v1.push_back(1);
        v1.push_back(1);

        print(v1);
    }
}