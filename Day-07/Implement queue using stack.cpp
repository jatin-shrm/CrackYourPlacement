#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        while (!s1.empty())
        {
            int el = s1.top();
            s1.pop();
            s2.push(el);
        }
        s1.push(x);
        while (!s2.empty())
        {
            int el = s2.top();
            s2.pop();
            s1.push(el);
        }
    }

    int pop()
    {
        int el = s1.top();
        s1.pop();
        return el;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};