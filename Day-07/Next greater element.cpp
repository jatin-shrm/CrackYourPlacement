#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int el = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int val = -1;
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            el = nums2[k];
                            break;
                        }
                    }
                    if (el != -1)
                        break;
                }
            }
            ans.push_back(el);
        }
        return ans;
    }
};