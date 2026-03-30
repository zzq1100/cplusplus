sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
set<int> num1(nums1.begin(), nums1.end());
set<int> num2(nums2.begin(), nums2.end());

vector<int> ret;
auto it1 = num1.begin();
auto it2 = num2.begin();
while (it1 != num1.end() && it2 != num2.end())
{
    if (*it1 < *it2)
        it1++;
    else if (*it2 < *it1)
        it2++;
    else
    {
        ret.push_back(*it1);
        it1++;
        it2++;
    }
}
return ret;