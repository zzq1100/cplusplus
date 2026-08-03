class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int n = arr.size();
        int count = 0, i = 0;

        for (i = 0; i < n; i++)
        {
            if (arr[i] != 0) count += 1;
            else count += 2;
            if (count >= n) break;
        }

        int j = n - 1;
        if (count > n)
        {
            arr[j] = 0;
            j--, i--;
        }
        while (j >= 0)
        {
            if (arr[i] != 0)
            {
                arr[j] = arr[i];
                j--;
            }
            else
            {
                arr[j] = 0;
                if (j - 1 >= 0) arr[j - 1] = 0;
                j -= 2;
            }
            i--;
        }
    }
};