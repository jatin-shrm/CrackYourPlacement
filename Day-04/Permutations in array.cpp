#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int i = 0;
        int j = arr2.size() - 1;
        while (i < arr1.size() && j >= 0)
        {
            if (arr1[i] + arr2[j] < k)
            {
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
};