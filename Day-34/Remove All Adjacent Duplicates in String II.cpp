#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                if (!st.empty() && st.top().first == s[i] && st.top().second == k - 1)
                {
                    st.pop();
                }
                else if (!st.empty() && st.top().first == s[i])
                {
                    st.top().second++;
                }
                else
                {
                    st.push({s[i], 1});
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans = string(st.top().second, st.top().first) + ans;
            st.pop();
        }
        return ans;
    }
};