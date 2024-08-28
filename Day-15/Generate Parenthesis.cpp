#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void generate(vector<string> &ans, string curr, int open, int close, int max)
    {
        if (curr.length() == 2 * max)
        {
            ans.push_back(curr);
        }
        if (open < max)
            generate(ans, curr + "(", open + 1, close, max);
        if (close < open)
            generate(ans, curr + ")", open, close + 1, max);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generate(ans, "", 0, 0, n);
        return ans;
    }
};