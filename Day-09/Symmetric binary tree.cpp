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
    bool isSame(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return root1 == root2;
        return (root1->val == root2->val) &&
               isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return isSame(root->left, root->right);
    }
};