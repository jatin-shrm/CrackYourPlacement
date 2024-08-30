#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> countNeighbors(const vector<vector<int>> &board, int r, int c)
    {
        int rows = board.size();
        int cols = board[0].size();

        int countZeroes = 0;
        int countOnes = 0;

        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (const auto &dir : directions)
        {
            int newRow = r + dir.first;
            int newCol = c + dir.second;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                if (board[newRow][newCol] == 0)
                {
                    countZeroes++;
                }
                else if (board[newRow][newCol] == 1)
                {
                    countOnes++;
                }
            }
        }

        return {countZeroes, countOnes};
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans = board;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pair<int, int> result = countNeighbors(board, i, j);
                if (result.second == 3)
                {
                    ans[i][j] = 1;
                }
                if (board[i][j] == 1)
                {
                    if (result.second < 2 || result.second > 3)
                    {
                        ans[i][j] = 0;
                    }
                }
            }
        }
        board = ans;
    }
};