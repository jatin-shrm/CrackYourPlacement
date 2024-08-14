#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        int i = 0;
        int j = m - 1;
        long long ans = INT_MAX;
        while (j < a.size())
        {
            ans = min((a[j] - a[i]), ans);
            i++;
            j++;
        }
        return ans;
    }
};