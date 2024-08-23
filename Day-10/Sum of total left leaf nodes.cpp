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
    void findsum(TreeNode *root, int &ans)
    {
        if (root != NULL)
        {
            if (root->left && !root->left->left && !root->left->right)
                ans += root->left->val;
            findsum(root->left, ans);
            findsum(root->right, ans);
        }
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        findsum(root, ans);
        return ans;
    }
};