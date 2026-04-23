#include<iostream>
using namespace std;


int main()
{
    int l, r, cnt = 0; cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 2) cnt++;
            tmp /= 10;
        }
    }
    cout << cnt << endl;

    return 0;
}