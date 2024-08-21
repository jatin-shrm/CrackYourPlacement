#include <bits/stdc++.h>
using namespace std;
class twoStacks
{
public:
    int *arr;
    int top1, top2;
    int size;
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            int el = arr[top1];
            top1--;
            return el;
        }
        return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 < size)
        {
            int el = arr[top2];
            top2++;
            return el;
        }
        return -1;
    }
};