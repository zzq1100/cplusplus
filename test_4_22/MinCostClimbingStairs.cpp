#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int cost[N] = {0};
int dp[N] = {0};

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
    }

    cout << dp[n] << endl;

    return 0;
}