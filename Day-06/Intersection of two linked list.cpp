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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *first = headA, *second = headB;
        while (first && second)
        {
            if (first == second)
                return first;
            first = first->next;
            second = second->next;
        }
        if (!first && !second)
            return 0;
        int c = 0;
        bool flag = true;
        while (first)
        {
            first = first->next;
            c++;
        }
        while (second)
        {
            second = second->next;
            c++;
            flag = false;
        }
        if (flag)
        {
            first = headA;
            second = headB;
            while (c > 0)
            {
                first = first->next;
                c--;
            }
            while (first && second)
            {
                if (first == second)
                    return first;
                first = first->next;
                second = second->next;
            }
        }
        else
        {
            first = headA;
            second = headB;
            while (c > 0)
            {
                second = second->next;
                c--;
            }
            while (first && second)
            {
                if (first == second)
                    return first;
                first = first->next;
                second = second->next;
            }
        }
        return 0;
    }
};