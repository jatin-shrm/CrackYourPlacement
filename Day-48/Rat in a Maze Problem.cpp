#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &mat, vector<vector<int>> &visited,
             vector<string> &ans, string s, int i, int j, char ch, vector<pair<int, int>> directions)
    {
        int row = mat.size();
        int col = mat[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || mat[i][j] == 0 || visited[i][j] == 1)
            return;

        visited[i][j] = 1;
        if (ch != '\0')
            s += ch;
        if (i == row - 1 && j == col - 1)
        {
            visited[i][j] = 0;
            ans.push_back(s);
            return;
        }
        for (int it = 0; it < 4; it++)
        {
            char c;
            if (it == 0)
                c = 'D';
            else if (it == 1)
                c = 'L';
            else if (it == 2)
                c = 'R';
            else
                c = 'U';
            dfs(mat, visited, ans, s, i + directions[it].first, j + directions[it].second, c, directions);
        }
        visited[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        int m = mat.size();
        int n = mat[0].size();
        if (mat[0][0] == 0 || mat[m - 1][n - 1] == 0)
            return {};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<string> ans;
        string s = "";

        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        dfs(mat, visited, ans, s, 0, 0, '\0', directions);
        return ans;
    }
};