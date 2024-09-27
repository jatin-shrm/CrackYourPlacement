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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        deque<TreeNode *> q;
        vector<vector<int>> ans;
        if (!root)
            return ans;
        q.push_front(root);
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                if (level % 2 == 0)
                {
                    TreeNode *temp = q.back();
                    q.pop_back();
                    v.push_back(temp->val);
                    if (temp->left)
                        q.push_front(temp->left);
                    if (temp->right)
                        q.push_front(temp->right);
                }
                else
                {
                    TreeNode *temp = q.front();
                    q.pop_front();
                    v.push_back(temp->val);
                    if (temp->right)
                        q.push_back(temp->right);
                    if (temp->left)
                        q.push_back(temp->left);
                }
            }
            level++;
            ans.push_back(v);
        }
        return ans;
    }
};