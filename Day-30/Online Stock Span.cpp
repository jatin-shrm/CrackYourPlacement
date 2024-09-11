#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
    vector<int> vec;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int n = vec.size();
        int i = n - 1;
        int span = 1;
        while (n > 0 && vec[i] <= price)
        {
            span++;
            i--;
            n--;
        }
        vec.push_back(price);
        return span;
    }
};