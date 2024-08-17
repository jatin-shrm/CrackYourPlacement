#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber-- > 0)
        {
            int r = columnNumber % 26;
            columnNumber = columnNumber / 26;
            char ch = 'A' + r;
            ans = ch + ans;
        }

        return ans;
    }
};