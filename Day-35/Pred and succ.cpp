#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    int small = INT_MIN;
    int big = INT_MAX;
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        if (!root)
            return;
        findPreSuc(root->left, pre, suc, key);
        if (root->key > small && root->key < key)
        {
            pre = root;
            small = root->key;
        }
        if (root->key > key && root->key < big)
        {
            suc = root;
            big = root->key;
        }
        findPreSuc(root->right, pre, suc, key);
    }
};