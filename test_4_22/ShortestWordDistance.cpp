#include<iostream>

using namespace std;


int main()
{
    int n; cin >> n;
    string s1, s2, s; cin >> s1 >> s2;

    int prev1 = -1, prev2 = -1, ret = INT_MAX, cnt = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s == s1)
        {
            if (prev2 != -1)
            {
                ret = min(ret, i - prev2);
            }
            prev1 = i;
        }
        if (s == s2)
        {
            if (prev1 != -1)
            {
                ret = min(ret, i - prev1);
            }
            prev2 = i;
        }
    }
    
    if (ret == INT_MAX)
        cout << "-1" << endl;
    else
        cout << ret << endl;

    return 0;
}