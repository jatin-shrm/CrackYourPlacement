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
    void findString(TreeNode *root, vector<int> &path, vector<string> &ans)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!(root->left) && !(root->right))
        {
            string s = "";
            s += to_string(path[0]);
            for (int i = 1; i < path.size(); i++)
            {
                s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
        }
        else
        {
            findString(root->left, path, ans);
            findString(root->right, path, ans);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {

        vector<string> ans;
        if (!root)
            return ans;
        vector<int> path;
        findString(root, path, ans);
        return ans;
    }
};