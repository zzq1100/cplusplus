#include<iostream>

using namespace std;

const int N = 1e7 + 10;
int a[N] = {0};

int main()
{
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 1, sum = 0, retl, retr, retlen = INT_MAX;
    while (r <= n)
    {
        sum += a[r];
        while (sum >= x)
        {
            if (r - l < retlen)
            {
                retl = l;
                retr = r;
                retlen = r - l;
            }
            sum -= a[l];
            l++;
        }
        r++;
    }

    cout << retl << " " << retr << endl;

    return 0;
}