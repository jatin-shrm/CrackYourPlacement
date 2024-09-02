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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *first = l1, *second = l2;
        ListNode *temp = new ListNode(-1);
        temp->next = first;
        int carry = 0;
        int sum = 0;
        while (first && second)
        {
            if (first)
            {
                sum += first->val;
                first = first->next;
            }
            if (second)
            {
                sum += second->val;
                second = second->next;
            }
            if (carry > 0)
            {
                sum += carry;
            }
            if (sum > 9)
            {
                temp->next->val = (sum % 10);
            }
            else
            {
                temp->next->val = sum;
            }
            carry = sum / 10;
            sum = 0;
            temp = temp->next;
        }
        if (!first && second)
        {
            temp->next = second;
        }
        while (first || second)
        {
            if (first)
            {
                sum += first->val;
                first = first->next;
            }
            if (second)
            {
                sum += second->val;
                second = second->next;
            }
            if (carry > 0)
            {
                sum += carry;
            }
            if (sum > 9)
            {
                temp->next->val = (sum % 10);
                carry = 1;
                sum = 0;
            }
            else
            {
                temp->next->val = sum;
                carry = 0;
                sum = 0;
            }
            temp = temp->next;
        }
        if (carry > 0)
        {
            ListNode *t = new ListNode(carry);
            temp->next = t;
            t->next = NULL;
        }
        return l1;
    }
};