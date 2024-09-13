#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            string s = tokens[i];
            if (isdigit(s[0]) || (s[0] == '-' && s.length() > 1))
            {
                int num = stoi(s);
                st.push(num);
            }
            else
            {
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if (s[0] == '*')
                {
                    st.push(first * sec);
                }
                else if (s[0] == '/')
                {
                    st.push(first / sec);
                }
                else if (s[0] == '-')
                {
                    st.push(first - sec);
                }
                else
                {
                    st.push(first + sec);
                }
            }
        }
        return st.top();
    }
};