#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {
        long long int prod = 1;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                prod *= nums[i];
            }
            else
            {
                count++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (count > 1)
            {
                nums[i] = 0;
            }
            else if (count == 0)
            {
                nums[i] = prod / nums[i];
            }
            else if (count == 1 && nums[i] != 0)
            {
                nums[i] = 0;
            }

            else
            {
                nums[i] = prod;
            }
        }
        return nums;
    }
};