#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < s.length())
            {
                if (j == strs[i].length())
                {
                    break;
                }
                else if (strs[i][j] != s[j])
                {
                    break;
                }
                j++;
            }
            s = s.substr(0, j);
            if (s.length() == 0)
                return "";
        }
        return s;
    }
};