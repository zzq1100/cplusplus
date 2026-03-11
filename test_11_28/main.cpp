#include<iostream>
using namespace std;
//
//int main()
//{
//	int num;
//	cin >> num;
//	int flag = 1;
//	int i = 0;
//	for (i = 0; ; i++)
//	{
//		for (int j = 2; j < num - 1 + i; j++)
//		{
//			if ((num - 1 + i) % j == 0)
//			{
//				flag = -1;
//				break;
//			}
//		}
//		if (flag == -1)
//			break;
//	}
//	cout << num + i << endl;
//	return 0;
//}

bool IsPrime(int& n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	cin >> num;
	while (!IsPrime(num))
	{
		num++;
	}
	cout << num << endl;
	return 0;
}