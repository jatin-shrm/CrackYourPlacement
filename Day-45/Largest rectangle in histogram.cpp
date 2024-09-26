#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &h)
    {
        int n = h.size(), ans = h[0];
        vector<vector<int>> v;
        v.push_back({h[0], 0});
        for (int i = 1; i < n; i++)
        {
            if (h[i] > v[v.size() - 1][0])
                v.push_back({h[i], i});
            else
            {
                int x;
                while (v.size() && v[v.size() - 1][0] >= h[i])
                {
                    ans = max(ans, v[v.size() - 1][0] * (i - v[v.size() - 1][1]));
                    x = v[v.size() - 1][1];
                    v.pop_back();
                }
                v.push_back({h[i], x});
            }
        }

        while (!v.empty())
        {
            ans = max(ans, v[v.size() - 1][0] * (n - v[v.size() - 1][1]));
            v.pop_back();
        }

        return ans;
    }
};