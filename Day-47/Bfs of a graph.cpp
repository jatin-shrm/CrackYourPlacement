#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for (auto it : adj[val])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        return ans;
    }
};