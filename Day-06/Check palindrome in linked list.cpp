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
    ListNode *reverse(ListNode *head)
    {
        ListNode *p = NULL;
        ListNode *q = NULL;
        ListNode *r = head;
        while (r)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        return q;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            ;
        }
        ListNode *p;
        p = reverse(slow);
        slow = head;
        while (p && slow)
        {
            if (slow->val != p->val)
            {
                return false;
            }
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};