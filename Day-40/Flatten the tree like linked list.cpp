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
    void flatten(TreeNode *root)
    {
        if (!root || (!root->right && !root->left))
            return;
        TreeNode *tempR = root->right;
        TreeNode *tempL = root->left;
        flatten(root->left);
        flatten(root->right);
        if (tempL)
        {
            root->right = tempL;
            root->left = NULL;
            while (tempL->right)
            {
                tempL = tempL->right;
            }
            tempL->right = tempR;
        }
        else
        {
            root->right = tempR;
        }
    }
};