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
    vector<TreeNode *> solve(int start, int end)
    {
        if (start > end)
            return {NULL};
        if (start == end)
        {
            TreeNode *temp = new TreeNode(start);
            return {temp};
        }
        vector<TreeNode *> result;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> LeftBst = solve(start, i - 1);
            vector<TreeNode *> RightBst = solve(i + 1, end);

            for (TreeNode *leftRoot : LeftBst)
            {
                for (TreeNode *rightRoot : RightBst)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};