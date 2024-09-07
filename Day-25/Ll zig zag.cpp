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
    Node *zigZag(Node *head)
    {
        // your code goes here
        if (!head || !head->next)
            return head;
        Node *p = head;
        while (p && p->next)
        {
            if (p->data > p->next->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            };
            p = p->next;
            if (p->next && p->data < p->next->data)
            {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
        return head;
    }
};