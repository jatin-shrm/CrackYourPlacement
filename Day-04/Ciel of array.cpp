#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCeil(vector<long long> &v, long long n, long long x)
    {

        // Your code here
        long long l = 0;
        long long h = n - 1;
        while (l <= h)
        {
            long long mid = l + (h - l) / 2;
            if (v[mid] == x)
            {
                return mid;
            }
            else if (v[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return l;
    }
};