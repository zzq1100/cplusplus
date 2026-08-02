#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
vector<int> nums(N);

void moveZeroes(vector<int> &nums)
{
    int dest = -1, cur = 0;
    while (cur < nums.size())
    {
        if (nums[cur] != 0)
        {
            dest++;
            swap(nums[dest], nums[cur]);
        }
        cur++;
    }
}

int main()
{
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}