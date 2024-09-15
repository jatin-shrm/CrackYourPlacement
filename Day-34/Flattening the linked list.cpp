#include <bits/stdc++.h>
using namespace std;
class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        // Initialize the stack with reversed nestedList
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it)
        {
            stack.push(*it);
        }
    }

    int next()
    {
        // Ensure there is a next integer
        if (hasNext())
        {
            // Pop and return the integer value
            NestedInteger top = stack.top();
            stack.pop();
            return top.getInteger();
        }
        return -1; // or handle this as needed
    }

    bool hasNext()
    {
        // Process the stack to find the next integer
        while (!stack.empty())
        {
            NestedInteger top = stack.top();
            if (top.isInteger())
            {
                return true;
            }
            stack.pop();
            const vector<NestedInteger> &nestedList = top.getList();
            for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it)
            {
                stack.push(*it);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> stack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */