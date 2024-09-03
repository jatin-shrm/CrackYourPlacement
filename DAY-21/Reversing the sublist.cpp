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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *temp = new ListNode(-1);
        ListNode *first = temp;
        temp->next = head;
        int count = left;
        for (int i = 1; i < left; i++)
            first = first->next;
        ListNode *curr = first->next;
        ListNode *p = NULL;
        for (int i = 0; i < right - left; i++)
        {
            p = curr->next;
            curr->next = p->next;
            p->next = first->next;
            first->next = p;
        }
        return temp->next;
    }
};