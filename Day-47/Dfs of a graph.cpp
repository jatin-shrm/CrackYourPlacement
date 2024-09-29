#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void Dfs(int root, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
    {
        if (!visited[root])
        {
            ans.push_back(root);
            visited[root] = true;
            for (auto it : adj[root])
            {
                if (!visited[it])
                    Dfs(it, adj, ans, visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        Dfs(0, adj, ans, visited);
        return ans;
    }
};