#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evaluatePostfix(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                int x = s[i] - '0';
                st.push(x);
            }
            else
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                if (s[i] == '*')
                {
                    st.push(x * y);
                }
                else if (s[i] == '/')
                {
                    st.push(x / y);
                }
                else if (s[i] == '+')
                {
                    st.push(x + y);
                }
                else
                {
                    st.push(x - y);
                }
            }
        }
        return st.top();
    }
};