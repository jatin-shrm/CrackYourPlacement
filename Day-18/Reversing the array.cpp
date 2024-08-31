#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i < nums.size() - 1 && nums[i] <= nums[i + 1])
    {
        i++;
    }
    if (i == nums.size() - 1)
        return true;
    while (j > i && nums[j] >= nums[j - 1])
    {
        j++;
    }
    if ((j < nums.size() - 1 && nums[i] > nums[j + 1]) || (i > 0 && nums[j] < nums[i - 1]))
        return false;
    while (i < j)
    {
        if (nums[i] < nums[i + 1])
            return false;
        i++;
    }
    return true;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9};
    return check(v);
}