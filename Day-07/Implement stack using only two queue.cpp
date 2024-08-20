#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    MyStack()
    {
    }
    queue<int> q1;
    queue<int> q2;

    void push(int x)
    {
        while (!q1.empty())
        {
            int el = q1.front();
            q1.pop();
            q2.push(el);
        }
        q1.push(x);
        while (!q2.empty())
        {
            int el = q2.front();
            q2.pop();
            q1.push(el);
        }
    }

    int pop()
    {
        int el = q1.front();
        q1.pop();
        return el;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
