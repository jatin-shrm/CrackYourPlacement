#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mctFromLeafValues(vector<int> &v)
    {
        int c = 0;     // 'c' stores the cumulative cost.
        stack<int> st; // 'st' is used to keep track of values from 'v' in a stack.

        for (int i : v)
        { // Loop through each element in the input vector 'v'.
            // While the stack is not empty and the top of the stack is less than or equal to 'i':
            while (!st.empty() && st.top() <= i)
            {
                int x = st.top(); // Get the top element of the stack.
                st.pop();         // Pop the top element of the stack.

                // Calculate the cost: x * min of the current top of the stack or 'i'.
                // If stack is empty, we use INT_MAX as a very large value.
                c += x * min(st.empty() ? INT_MAX : st.top(), i);
            }
            st.push(i); // Push the current value 'i' onto the stack.
        }

        // After the loop, we need to process the remaining elements in the stack.
        int a = st.top(); // Start with the top element of the stack.
        st.pop();         // Pop the top element of the stack.

        // Process the remaining elements in the stack.
        while (!st.empty())
        {
            int x = st.top(); // Get the top element of the stack.
            st.pop();         // Pop the top element of the stack.

            // Add to cost: x * min of the new top of the stack or 'a'.
            c += x * min(st.empty() ? INT_MAX : st.top(), a);
            a = x; // Update 'a' to be the last popped value.
        }

        return c; // Return the final cumulative cost.
    }
};