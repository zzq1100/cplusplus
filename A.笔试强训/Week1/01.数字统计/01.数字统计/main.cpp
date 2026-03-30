#include<iostream>
using namespace std;


int main()
{
	int l, r; cin >> l >> r;

	int cnt = 0;
	for (int i = l; i <= r; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 2)
				cnt++;
			tmp /= 10;
		}
	}

	cout << cnt << endl;


	return 0;
}