#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *p = NULL;
        Node *q = NULL;
        Node *r = head;
        while (r)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        return q;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node *first = reverse(head);
        Node *h = first;
        int maxi = 0;
        while (first && first->next)
        {
            maxi = max(maxi, first->data);
            if (first->next->data < maxi)
            {
                first->next = first->next->next;
            }
            else
            {
                first = first->next;
            }
        }
        Node *ans = reverse(h);
        return ans;
    }
};