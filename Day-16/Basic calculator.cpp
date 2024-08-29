#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calculate(string s)
    {
        s += '+';
        char sign = '+';
        int curr = 0;
        long long ans = 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                curr = curr * 10 + (s[i] - '0');
            else if (s[i] == '+' || s[i] == '/' || s[i] == '*' || s[i] == '-')
            {
                if (sign == '+')
                {
                    st.push(curr);
                }
                else if (sign == '-')
                {
                    st.push(-curr);
                }
                else if (sign == '*')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num * curr);
                }
                else
                {
                    int num = st.top();
                    st.pop();
                    st.push(num / curr);
                }
                curr = 0;
                sign = s[i];
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};