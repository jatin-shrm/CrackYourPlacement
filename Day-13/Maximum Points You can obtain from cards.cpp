#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += cardPoints[i];
        }
        int res = ans;
        int i = k, j = n - 1;
        while (k > 0)
        {
            res = res + cardPoints[j] - cardPoints[i - 1];
            j--;
            i--;
            ans = max(ans, res);
            k--;
        }
        return ans;
    }
};