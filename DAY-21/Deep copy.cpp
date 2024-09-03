#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mpp;
        Node *curr = head;
        while (curr)
        {
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            mpp[curr]->next = mpp[curr->next];
            mpp[curr]->random = mpp[curr->random];
            curr = curr->next;
        }
        return mpp[head];
    }
};