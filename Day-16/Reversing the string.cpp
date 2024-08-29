#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;
            string temp = "";
            while (i < s.length() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            if (ans.length() == 0)
                ans += temp;
            else
                ans = temp + " " + ans;
        }
        return ans;
    }
};