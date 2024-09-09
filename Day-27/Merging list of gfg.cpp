#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *merger(Node *l1, Node *l2)
    {
        Node *temp = new Node(-1);
        Node *dummy = temp;
        while (l1 && l2)
        {
            if (l1->data <= l2->data)
            {
                dummy->bottom = l1;
                l1 = l1->bottom;
            }
            else
            {
                dummy->bottom = l2;
                l2 = l2->bottom;
            }
            dummy = dummy->bottom;
        }
        dummy->bottom = l1 ? l1 : l2;
        return temp->bottom;
    }

    Node *flatten(Node *root)
    {
        // Base case: if the root is null or there is no next list to flatten
        if (!root || !root->next)
            return root;
        root->next = flatten(root->next);
        root = merger(root, root->next);
        return root;
    }
};
