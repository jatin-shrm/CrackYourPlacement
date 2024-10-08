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
    int check(TreeNode *root, bool &ans)
    {
        if (!root || !ans)
            return 0;
        int lh = check(root->left, ans);
        int rh = check(root->right, ans);
        if (abs(lh - rh) > 1)
        {
            ans = false;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        check(root, ans);
        return ans;
    }
};