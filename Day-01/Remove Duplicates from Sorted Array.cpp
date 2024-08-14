#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        int j = i;
        while (i < nums.size() && j < nums.size())
        {
            if (nums[i] != nums[j])
            {
                swap(nums[i + 1], nums[j]);
                i++;
            }
            j++;
        }
        return i + 1;
    }
};