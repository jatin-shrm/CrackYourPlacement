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
    ListNode *divide(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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
        while (l1)
        {
            dummy->next = l1;
            l1 = l1->next;
            dummy = dummy->next;
        }
        while (l2)
        {
            dummy->next = l2;
            l2 = l2->next;
            dummy = dummy->next;
        }
        return temp->next;
    }
    ListNode *mergeSort(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *middle = divide(head);
        ListNode *right = middle->next;
        middle->next = NULL;
        ListNode *left = head;
        left = mergeSort(left);
        right = mergeSort(right);
        return merger(left, right);
    }
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};