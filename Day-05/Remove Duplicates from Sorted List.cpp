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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        while (second)
        {
            while (second && second->val == first->val)
                second = second->next;
            first->next = second;
            first = first->next;
            if (second)
                second = second->next;
        }
        return head;
    }
};