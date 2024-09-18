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
    void getCount(TreeNode *root, int targetSum, long long currentSum, int &count)
    {
        if (!root)
            return;
        currentSum += root->val;
        if (currentSum == targetSum)
        {
            count++;
        }
        getCount(root->left, targetSum, currentSum, count);
        getCount(root->right, targetSum, currentSum, count);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        int count = 0;
        getCount(root, targetSum, 0, count);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};