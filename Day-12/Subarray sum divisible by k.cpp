#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int sum = 0;
        map<int, int> mpp;
        mpp[sum]++;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (mpp.find(rem) != mpp.end())
            {
                count += mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};