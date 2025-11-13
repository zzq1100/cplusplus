#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;
	int& c = b;
	cout << a << endl << b << endl << c << endl;
	cout << &a << endl << &b << endl << &c << endl;

	FILE* pf = fopen("test.c", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fclose(pf);
	pf = NULL;
	return 0;
}
namespace bit
{
	// 命名空间中可以定义变量
		//函数
		//类型

		int rand = 10;
	int Add(int left, int right)
	{
		return left + right;
	}
	struct Node
	{
		struct Node* next;
		int val;
	};
}