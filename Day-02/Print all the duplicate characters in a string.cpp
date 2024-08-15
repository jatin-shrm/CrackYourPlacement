#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int duplicateChar(string S)
    {
        // code here

        int count = 0;
        map<char, int> mpp;
        for (int i = 0; i < S.length(); i++)
        {
            mpp[S[i]]++;
        }
        for (auto it : mpp)
        {
            cout << "Element " << it.first << " appears " << it.second << endl;
        }
        return count;
    }
};