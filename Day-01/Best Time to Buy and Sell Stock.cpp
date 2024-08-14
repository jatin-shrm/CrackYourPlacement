#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > minPrice)
            {
                ans = max(prices[i] - minPrice, ans);
            }
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
        }
        return ans;
    }
};