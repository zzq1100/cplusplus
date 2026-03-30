#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double kg; cin >> kg;
    char yn; cin >> yn;

    int sum = 20;
    if (kg <= 1)
    {
        if (yn == 'y')
        {
            sum += 5;
        }
    }
    else
    {
        kg -= 1;
        kg = ceil(kg);
        sum += kg;
        if (yn == 'y')
        {
            sum += 5;
        }
    }
    cout << sum;
}
