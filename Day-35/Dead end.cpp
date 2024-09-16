#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
};
class Solution
{
public:
    void deadEnd(Node *root, int l, int r, bool &flag)
    {
        if (!root || flag)
            return;
        if (!root->left && !root->right)
        {
            if (l == r)
            {
                flag = true;
            }
            return;
        }
        deadEnd(root->left, l, root->data - 1, flag);
        deadEnd(root->right, root->data + 1, r, flag);
    }
    bool isDeadEnd(Node *root)
    {
        // Your code here
        bool flag = false;
        deadEnd(root, 1, INT_MAX, flag);
        return flag;
    }
};