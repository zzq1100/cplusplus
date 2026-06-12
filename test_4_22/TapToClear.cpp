#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

// int main()
// {
//     string s; cin >> s;

//     string st;

//     for (auto ch : s)
//     {
//         if (st.size() && st.back() == ch) st.pop_back();
//         else st += ch;
//     }
//     cout << st << endl;

//     return 0;
// }

int main()
{
    string s; cin >> s;
    stack<char> st;

    for (auto ch : s)
    {
        if (!st.empty() && st.top() == ch)
            st.pop();
        else
            st.push(ch);
    }

    string ret;
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }

    reverse(ret.begin(), ret.end());

    cout << ret << endl;

    return 0;
}