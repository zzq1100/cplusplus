#include"HashTable.h"

int main()
{
	int arr[] = { 3, 44, 32,332,4324,432,4,4325,3 };
	
	HashTable<int, int> ht;
	for (auto e : arr)
	{
		ht.Insert({ e, e });
	}

	

	return 0;
}