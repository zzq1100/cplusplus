#include<iostream>
#include<string>

using namespace std;


int main()
{
    string s;
    while (cin >> s)
    {
        if (s[0] >= 'a' && s[0] <= 'z') cout << (char)(s[0] - 32);
        else cout << s[0];
    }

    return 0;
}