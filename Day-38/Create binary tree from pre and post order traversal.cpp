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
    TreeNode *dfs(vector<int> &preorder, int preStart, int preEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if (preStart > preEnd || postStart > postEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;
        int postIndex = postStart;
        while (postIndex <= postEnd)
        {
            if (postorder[postIndex] == preorder[preStart + 1])
                break;
            postIndex++;
        }
        int len = postIndex - postStart + 1;
        root->left = dfs(preorder, preStart + 1, preStart + len, postorder, postStart, postIndex);
        root->right = dfs(preorder, preStart + len + 1, preEnd, postorder, postIndex + 1, postEnd - 1);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return dfs(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};