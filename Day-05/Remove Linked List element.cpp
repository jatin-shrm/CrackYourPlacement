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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;
        ListNode *first = head;
        while (first && first->val == val)
            first = first->next;
        head = first;
        if (!head)
            return head;
        ListNode *sec = head->next;
        while (sec)
        {
            while (sec && sec->val == val)
                sec = sec->next;
            first->next = sec;
            first = first->next;
            if (sec)
                sec = sec->next;
        }
        return head;
    }
};