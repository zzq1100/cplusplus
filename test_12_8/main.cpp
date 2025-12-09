

//const int N = 2e6 + 10;
//vector<int> a(N);
//int n, m;
//int  main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	while (m--)
//	{
//		int x;
//		cin >> x;
//		cout << a[x] << endl;
//	}
//	return 0;
//}



//const int N = 1e5 + 10;
//vector<int> a[N];
//int n, q;


//int main()
//{
//	cin >> n >> q;
//	while (q--)
//	{
//		int op, i, j, k;
//		cin >> op >> i >> j;
//		if (op == 1)
//		{
//			cin >> k;
//			if (k == 0)
//				a[j].clear();
//			else
//			{
//				if (j >= a[i].size())
//				{
//					a[i].resize(j + 1);
//				}
//				a[i][j] = k;
//			}
//		}
//		else
//		{
//			cout << a[i][j] << endl;;
//		}
//	}
//	return 0;
//}

//int i = 0, cur = -1;
//for (i = 0; i < nums.size(); i++)
//{
//    if (nums[i])
//    {
//        swap(nums[i], nums[++cur]);
//    }
//}

//int i = 0, cur = -1;
//for (i = 0; i < nums.size(); i++)
//{
//    if (nums[i])
//    {
//        swap(nums[i], nums[++cur]);
//    }
//}

//int i = 0, cur = -1;
//for (i = 0; i < nums.size(); i++)
//{
//    if (nums[i])
//    {
//        swap(nums[i], nums[++cur]);
//    }
//}

//int i = 0, cur = -1;
//for (i = 0; i < nums.size(); i++)
//{
//    if (nums[i])
//    {
//        swap(nums[i], nums[++cur]);
//    }
//}


#include <iostream>
#include <vector>
using namespace std;

int n;
const int N = 30;
vector<int> p[N];
typedef pair<int, int> PII;

PII find(int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < p[i].size(); j++)
		{
			if (p[i][j] == x)
				return { i, j };
		}
	}
}

void clear(int x, int y)
{
	for (int i = y + 1; i < p[x].size(); i++)
	{
		int tmp = p[x][i];
		p[tmp].push_back(tmp);
	}
	p[x].resize(y + 1);
}

void move(int x1, int y1, int x2)
{
	for (int i = y1; i < p[x1].size(); i++)
	{
		int tmp = p[x1][i];
		p[x2].push_back(tmp);
	}
	p[x1].resize(y1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p[i].push_back(i);
	}

	string op1, op2;
	int a, b;
	while (cin >> op1 >> a >> op2 >> b)
	{
		PII x = find(a);
		PII y = find(b);
		int x1 = x.first, y1 = x.second;
		int x2 = y.first, y2 = y.second;

		if (x1 == x2)
			continue;

		if (op1 == "move")
		{
			clear(x1, y1);
		}

		if (op2 == "onto")
		{
			clear(x2, y2);
		}

		move(x1, y1, x2);
		for (int i = 0; i < n; i++)
		{
			cout << i << ':' << ' ';
			for (int j = 0; j < p[i].size(); j++)
			{
				cout << p[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}