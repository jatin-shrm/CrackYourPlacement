#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int start = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (start < prices[i])
            {
                ans += prices[i] - start;
            }
            start = prices[i];
        }
        return ans;
    }
};