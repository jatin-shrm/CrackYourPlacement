#include <bits/stdc++.h>
using namespace std;
long long Nstudents(int arr[], int pages, int n)
{
    int student = 0;
    long long book = 0;
    for (int i = 0; i < n; i++)
    {
        if (book + arr[i] <= pages)
        {
            book += arr[i];
        }
        else
        {
            student++;
            book = arr[i];
        }
    }
    return student;
}
long long findPages(int n, int arr[], int m)
{
    // code here
    if (n < m)
        return -1;
    int low = *max_element(arr, arr + n);
    int high = accumulate(arr, arr + n, 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int student = Nstudents(arr, mid, n);
        if (student > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}