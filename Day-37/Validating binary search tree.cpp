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
    bool validator(TreeNode *root, long int l, long int r)
    {
        if (!root)
            return true;
        if (root->val < l || root->val > r)
            return false;
        return validator(root->left, l, (long int)root->val - 1) && validator(root->right, (long int)root->val + 1, r);
    }
    bool isValidBST(TreeNode *root)
    {
        return validator(root, LONG_MIN, LONG_MAX);
    }
};