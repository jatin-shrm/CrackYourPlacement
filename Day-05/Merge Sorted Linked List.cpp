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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }
        ListNode *head = new ListNode(-1);
        ListNode *last = head;

        ListNode *first = list1;
        ListNode *second = list2;

        while (first && second)
        {
            if (first->val <= second->val)
            {
                last->next = first;
                last = first;
                first = first->next;
            }
            else
            {
                last->next = second;
                last = second;
                second = second->next;
            }
        }
        if (second)
        {
            last->next = second;
        }
        if (first)
        {
            last->next = first;
        }
        return head->next;
    }
};