#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s; cin >> s;
	stack<char> st;

	for (auto e : s)
	{
		if (!st.empty() && st.top() == e)
		{
			st.pop();
		}
		else 
		{
			st.push(e);
		}
	}
	
	if (st.empty())
	{
		cout << 0 << endl;
	}
	else
	{
		string tmp;
		while (!st.empty())
		{
			tmp += st.top();
			st.pop();
		}
		reverse(tmp.begin(), tmp.end());
		cout << tmp << endl;
	}


	return 0;
}