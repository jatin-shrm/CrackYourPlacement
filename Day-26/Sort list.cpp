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
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *p = head;
        vector<int> v;
        while (p != NULL)
        {
            v.push_back(p->val);
            p = p->next;
        }
        p = head;
        sort(v.begin(), v.end());
        for (auto it : v)
        {
            p->val = it;
            p = p->next;
        }
        return head;
    }
};