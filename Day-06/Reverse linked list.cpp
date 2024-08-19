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

        ListNode *p = NULL, *q = NULL, *r = head;
        while (r)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        return q;
    }
};