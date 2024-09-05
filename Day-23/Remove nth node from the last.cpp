#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
            return NULL;
        ListNode *first = new ListNode;
        first->next = head;
        for (int i = 0; i < n; i++)
        {
            first = first->next;
        }
        ListNode *second = new ListNode;
        second->next = head;
        while (first->next)
        {
            second = second->next;
            first = first->next;
        }
        if (second->next == head)
            return head->next;
        second->next = second->next->next;
        return head;
    }
};