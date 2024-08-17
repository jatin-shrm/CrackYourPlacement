#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        int l = 0, h = 1;
        while (l <= h && h < n)
        {
            if ((l != h) && arr[h] - arr[l] == x)
            {
                return 1;
            }
            else if (arr[h] - arr[l] > x)
            {
                l++;
            }
            else
            {
                h++;
            }
        }
        return -1;
    }
};