#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int r, int c, int pos)
    {
        // Checing if we mathced the word
        if (pos == word.size())
            return true;
        int rows = board.size();
        int col = board[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= col || word[pos] != board[r][c])
            return false;
        char temp = board[r][c];
        board[r][c] = '#';
        int res = dfs(board, word, r + 1, c, pos + 1) ||
                  dfs(board, word, r - 1, c, pos + 1) ||
                  dfs(board, word, r, c + 1, pos + 1) ||
                  dfs(board, word, r, c - 1, pos + 1);
        board[r][c] = temp;
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int col = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};