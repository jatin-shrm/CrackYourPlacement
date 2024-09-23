#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high, int &count)
    {
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > 2 * (long long)arr[j])
                j++;
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int> &arr, int low, int high, int &count)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, high, count);
        merge(arr, low, mid, high, count);
    }

    int reversePairs(vector<int> &arr)
    {
        int count = 0;
        mergeSort(arr, 0, arr.size() - 1, count);
        return count;
    }
};