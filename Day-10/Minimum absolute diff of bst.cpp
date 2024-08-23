#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void getDiff(TreeNode *root, int &prev, int &ans)
    {
        if (root != NULL)
        {
            getDiff(root->left, prev, ans);
            ans = min(root->val - prev, ans);
            prev = root->val;
            getDiff(root->right, prev, ans);
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        int prev = -1e9;
        int ans = INT_MAX;
        getDiff(root, prev, ans);
        return ans;
    }
};