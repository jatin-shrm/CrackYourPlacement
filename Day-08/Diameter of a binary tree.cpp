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
    int ans = 0;
    int height(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }
        else
        {
            int lh = height(root->left);
            int rh = height(root->right);
            ans = max(ans, lh + rh);
            return 1 + max(lh, rh);
        }

        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        height(root);
        return ans;
    }
};