//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n; cin >> n;
//	for (int i = n; i >= 0; i--)
//	{
//		int a; cin >> a;
//		if (a == 0) continue;
//		if (a < 0) cout << "-";
//		else if (n != i) cout << "+";
//
//		a = abs(a);
//		
//		if (a != 1) cout << a;
//		else if (i == 0) cout << a;
//
//		if (i == 0) continue;
//		if (i == 1) cout << "x";
//		else cout << "x^" << i;
//		
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//
//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };
//int arr[15][15] = { 0 };
//
//int main()
//{
//	int n; cin >> n;
//	int x = 1, y = 1, pos = 0;
//	for (int i = 1; i <= n * n; i++)
//	{
//		arr[x][y] = i;
//		
//		int a = x + dx[pos], b = y + dy[pos];
//		if (a > n || b > n || b < 1 || arr[a][b] != 0)
//		{
//			pos = (pos + 1) % 4;
//			a = x + dx[pos], b = y + dy[pos];
//		}
//		x = a, y = b;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%3d", arr[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;

int p1, p2, p3, n;
string s;
string ret;

bool isdig(char ch) { return ch >= '0' && ch <= '9'; }
bool islet(char ch) { return ch >= 'a' && ch <= 'z'; }
void add(char left, char right)
{
	string tmp;
	for (char ch = left + 1; ch < right; ch++)
	{
		char t = ch;
		if (p1 == 2 && islet(t)) t = ch - 32;
		else if (p1 == 3) t = '*';
		for (int i = 0; i < p2; i++)
		{
			tmp += t;
		}
	}
	if (p3 == 2) reverse(tmp.begin(), tmp.end());
	ret += tmp;
}


int main()
{
	cin >> p1 >> p2 >> p3 >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		char ch = s[i];
		if (ch != '-' || i == 0 || i == n - 1) ret += ch;
		else 
		{
			char left = s[i - 1], right = s[i + 1];
			if (isdig(left) && isdig(right) && left < right ||
				islet(left) && islet(right) && left < right)
				add(left, right);
			else ret += ch;
		}
		
	}
	cout << ret;
	return 0;
}