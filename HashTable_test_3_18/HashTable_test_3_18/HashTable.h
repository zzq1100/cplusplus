#pragma once
#include<iostream>
#include<vector>

using namespace std;

enum State
{
	EMPTY, EXIST, DELETE
};

template <class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template <class K, class V>
class HashTable
{
public:
	HashTable()
		:_tables(11)
		,_n(0)
	{ }

	bool Insert(const pair<K, V>& kv)
	{
		if ((double)_n / _tables.size() >= 0.7)
		{
			HashTable<K, V> newbt;
			newbt._tables.resize(_tables.size() * 2);
			for (auto& data : _tables)
			{
				if (data._state == EXIST)
				{
					newbt.Insert(data._kv);
				}
			}
			_tables.swap(newbt._tables);
		}

		size_t hash0 = kv.first % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state == EXIST)
		{
			hashi = (hash0 + i) % _tables.size();
			i++;
		}
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		_n++;
		return true;
	}

	HashData<K, V>* Find(const K& key)
	{
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
			{
				return &_tables[hashi];
			}
			hashi = (hash0 + i) % _tables.size();
			i++;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret == nullptr)
		{
			return false;
		}
		else
		{
			ret->_state = DELETE;
			_n--;
			return true;
		}
	}

private:
	vector<HashData<K, V>> _tables;
	size_t _n = 0;
};