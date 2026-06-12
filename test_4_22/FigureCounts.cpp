#include<iostream>

using namespace std;

int main()
{
    int l, r; cin >> l >> r;
    int count = 0;

    for (int i = l; i <= r; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 2) count++;
            tmp /= 10;
        }
    }
    
    cout << count << endl;
    return 0;
}