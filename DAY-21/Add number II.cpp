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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *p = NULL, *q = head, *r = head->next;
        while (r)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        return q;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = reverseList(l1);
        ListNode *t2 = reverseList(l2);
        ListNode *first = t1, *second = t2;
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
        ListNode *ans = reverseList(t1);
        return ans;
    }
};