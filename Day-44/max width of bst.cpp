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
typedef long long ll;
ll mod = 1e11;
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, ll>> q;
        if (!root)
            return 0;
        int ans = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            ll n = q.size();
            ll mmin = q.front().second;
            int first, last;
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front().first;
                ll index = q.front().second - mmin;
                q.pop();
                if (i == 0)
                    first = index;
                if (i == n - 1)
                    last = index;
                if (temp->left)
                {
                    q.push({temp->left, 2 * index + 1});
                }
                if (temp->right)
                {
                    q.push({temp->right, 2 * index + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};