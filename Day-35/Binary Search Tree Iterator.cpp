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
class BSTIterator
{
public:
    vector<int> arr;
    int curr = 0;
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        arr.push_back(root->val);
        helper(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        helper(root);
    }

    int next()
    {
        return arr[curr++];
    }

    bool hasNext()
    {
        return arr.size() != curr;
    }
};