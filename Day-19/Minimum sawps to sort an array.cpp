#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        int c = 0;
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != arr[i].first)
            {
                c++;
                swap(arr[i], arr[arr[i].second]);
                i--;
            }
        }

        return c;
    }
};