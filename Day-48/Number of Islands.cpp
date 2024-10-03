#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(vector<vector<char>> &grid, int i, int j)
    {
        int row = grid.size();
        int col = grid[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0' || grid[i][j] == '2')
            return false;
        grid[i][j] = '2';
        return dfs(grid, i, j + 1) || dfs(grid, i + 1, j) || dfs(grid, i, j - 1) || dfs(grid, i - 1, j);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int no_of_island = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    no_of_island++;
                    dfs(grid, i, j);
                }
            }
        }
        return no_of_island;
    }
};