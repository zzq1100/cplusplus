#include<iostream>
#include<queue>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k, a, sum = 0; cin >> n >> k;

    priority_queue<ll> pq;
    while (n--)
    {
        cin >> a;
        sum += a;
        if (a % 2 == 0) pq.push(a);
    }
    ll tmp;
    while (k--)
    {
        if (!pq.empty())
        {
            tmp = pq.top();
            pq.pop();
            sum -= (tmp / 2);
        }
    }

    cout << sum << endl;




    return 0;
}