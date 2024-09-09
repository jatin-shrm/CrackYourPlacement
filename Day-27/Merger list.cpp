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
    ListNode *merger(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(-1);
        ListNode *dummy = temp;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                dummy->next = l1;
                l1 = l1->next;
            }
            else
            {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = l1 ? l1 : l2;
        return temp->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode *ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            ListNode *sec = lists[i];
            ans = merger(ans, sec);
        }
        return ans;
    }
};