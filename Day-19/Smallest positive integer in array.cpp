#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        int count = 1;
        map<int, int> mpp;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                mpp[arr[i]]++;
            }
        }
        for (auto it : mpp)
        {
            // if(mpp.find(count)!=mpp.end())count++;
            if (it.first == count)
                count++;
            else
                return count;
        }
        return count;
    }
};