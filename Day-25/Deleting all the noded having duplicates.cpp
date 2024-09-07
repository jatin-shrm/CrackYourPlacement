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
        ListNode *temp = new ListNode(0);
        ListNode *dummy = temp;
        bool flag = true;
        while (head)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                    head = head->next;
                head = head->next;
                continue;
            }
            dummy->next = head;
            dummy = dummy->next;
            head = head->next;
        }
        dummy->next = NULL;
        return temp->next;
    }
};