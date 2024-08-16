#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        string res = "";
        while (i >= 0 && j >= 0)
        {
            if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1'))
            {
                if (carry == 0)
                {
                    res = "1" + res;
                    carry = 0;
                }
                else
                {
                    res = "0" + res;
                    carry = 1;
                }
            }
            else if (a[i] == '0' && b[j] == '0')
            {
                char ch = '0' + carry;
                res = ch + res;
                carry = 0;
            }
            else
            {
                if (carry == 0)
                {
                    res = "0" + res;
                    carry = 1;
                }
                else
                {
                    char ch = '0' + 1;
                    res = ch + res;
                    carry = 1;
                }
            }
            i--;
            j--;
        }
        while (i >= 0)
        {
            if ((a[i] == '1' && carry == 0) || (a[i] == '0' && carry == 1))
            {
                res = "1" + res;
                carry = 0;
            }
            else if (a[i] == '1' && carry == 1)
            {
                res = "0" + res;
                carry = 1;
            }
            else
            {
                res = "0" + res;
                carry = 0;
            }
            i--;
        }
        while (j >= 0)
        {
            if ((b[j] == '1' && carry == 0) || (b[j] == '0' && carry == 1))
            {
                res = "1" + res;
                carry = 0;
            }
            else if (b[j] == '1' && carry == 1)
            {
                res = "0" + res;
                carry = 1;
            }
            else
            {
                res = "0" + res;
                carry = 0;
            }
            j--;
        }
        if (carry == 1)
        {
            res = "1" + res;
        }
        return res;
    }
};