
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
    int count = 0;
    int getCount(TreeNode *root, int l, int h)
    {
        // your code goes here
        if (root != NULL)
        {
            getCount(root->left, l, h);
            if (root->val >= l && root->val <= h)
                count++;
            getCount(root->right, l, h);
        }
        return count;
    }
};