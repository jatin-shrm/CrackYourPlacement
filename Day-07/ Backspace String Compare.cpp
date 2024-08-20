#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string afterBackspace(string s)
    {
        stack<char> s1;
        stack<char> s2;
        int i = s.length() - 1;
        string ans = "";
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                s2.push(s[i]);
            }
            else
            {
                if (s2.empty())
                {
                    s1.push(s[i]);
                }
                else
                {
                    s2.pop();
                }
            }
            i--;
        }
        while (!s1.empty())
        {
            ans += s1.top();
            s1.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t)
    {
        return afterBackspace(s) == afterBackspace(t);
    }
};