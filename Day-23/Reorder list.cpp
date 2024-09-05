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
    void reorderList(ListNode *head)
    {
        ListNode *first = head;
        vector<int> v;
        while (first)
        {
            v.push_back(first->val);
            first = first->next;
        }
        int l = 0;
        int h = v.size() - 1;
        first = head;
        while (first)
        {
            first->val = v[l];
            l++;
            first = first->next;
            if (first)
            {
                first->val = v[h];
                first = first->next;
            }
            h--;
        }
        // return head;
    }
};