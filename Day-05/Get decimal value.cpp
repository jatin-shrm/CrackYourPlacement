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
    int getDecimalValue(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while (fast->next)
        {
            count++;
            fast = fast->next;
        }
        int ans = 0;
        while (slow)
        {
            ans += (slow->val) * pow(2, count);
            slow = slow->next;
            count--;
        }
        return ans;
    }
};