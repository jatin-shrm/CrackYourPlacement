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
    int cnt = 0;
    void inorder(TreeNode *root, int k, int &ans)
    {
        if (!root || cnt == k)
            return;
        inorder(root->left, k, ans);
        cnt++;
        if (cnt == k)
            ans = root->val;
        inorder(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};