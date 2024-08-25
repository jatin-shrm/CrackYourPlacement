#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int count = 0;
        map<int, int> mpp;
        mpp[sum]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (mpp.find(sum - k) != mpp.end())
            {
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};