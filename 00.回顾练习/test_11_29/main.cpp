#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void SortPrint(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int* arr, int n)
{
	for (int i = 0; i <= n - 2; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
		}
		arr[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 1,5,3,3,43,534,34,3,42,4,234,23 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	SortPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}