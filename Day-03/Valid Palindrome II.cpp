#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkRemover(int start, int end, string s)
    {
        int i = start, j = end;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return (checkRemover(i + 1, j, s)) || (checkRemover(i, j - 1, s));
            }
            i++;
            j--;
        }
        return true;
    }
};