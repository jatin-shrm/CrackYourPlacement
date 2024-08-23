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
    bool checkSum(TreeNode *root, int targetSum, int sum)
    {
        if (!root)
            return false;
        sum += root->val;
        if (!root->left && !root->right)
        {
            if (sum == targetSum)
                return true;
        }
        return checkSum(root->left, targetSum, sum) ||
               checkSum(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return checkSum(root, targetSum, 0);
    }
};