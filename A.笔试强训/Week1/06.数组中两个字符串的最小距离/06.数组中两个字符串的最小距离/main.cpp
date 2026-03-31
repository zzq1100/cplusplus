#include <iostream>
using namespace std;


int main()
{
    int n; cin >> n;
    string str1, str2; cin >> str1 >> str2;

    if (str1 == " " || str2 == " ")
        return -1;

    int prev1 = -1; int prev2 = -1; int ret = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string strs;
        cin >> strs;
        if (strs == str1)
        {
            prev1 = i;
            if (prev2 != -1)
                ret = min(prev1 - prev2, ret);
        }
        if (strs == str2)
        {
            prev2 = i;
            if (prev1 != -1 && prev1 != i)
                ret = min(prev2 - prev1, ret);
        }

    }

    if (ret == INT_MAX)
        cout << -1;
    else
        cout << ret;

    return 0;
}

