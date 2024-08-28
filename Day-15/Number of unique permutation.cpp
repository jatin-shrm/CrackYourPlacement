#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void perm(vector<int> &nums, int pos, vector<vector<int>> &ans)
    {
        if (pos >= nums.size())
        {
            ans.push_back(nums);
        }
        unordered_set<int> s;
        for (int i = pos; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[i], nums[pos]);
            perm(nums, pos + 1, ans);
            swap(nums[pos], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        perm(nums, 0, ans);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};