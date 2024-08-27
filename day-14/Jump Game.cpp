#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int i = nums.size() - 1;
        int el = i;
        while (i >= 0)
        {
            int dist = el - i;
            if (nums[i] >= dist)
            {
                el = i;
            }
            i--;
        }
        if (el == 0)
            return true;
        return false;
    }
};