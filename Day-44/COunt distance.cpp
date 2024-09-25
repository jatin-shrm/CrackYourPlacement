#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                parent_track[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                parent_track[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markParents(root, parent_track, target);
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        q.push(target);
        vis[target] = true;
        int curr_level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (curr_level++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (parent_track[temp] && !vis[parent_track[temp]])
                {
                    q.push(parent_track[temp]);
                    vis[parent_track[temp]] = true;
                    ;
                }
                if (temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left] = true;
                    ;
                }
                if (temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right] = true;
                    ;
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};