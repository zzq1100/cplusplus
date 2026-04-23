#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n; cin >> n;
    string s, s1, s2; cin >> s1 >> s2;

    int prev1 = -1, prev2 = -1, retlen = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s == s1)
        {
            if (prev2 != -1)
            {
                retlen = min(retlen, i - prev2);
            }
            prev1 = i;
        }
        if (s == s2)
        {
            if (prev1 != -1)
            {
                retlen = min(retlen, i - prev1);
            }
            prev2 = i;
        }
    }
    if (retlen == INT_MAX) cout << "-1" << endl;
    else cout << retlen << endl;


    return 0;
}