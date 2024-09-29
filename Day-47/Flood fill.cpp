#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, int val, int color)
    {
        int row = image.size();
        int col = image[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || image[i][j] != val)
            return;
        image[i][j] = color;
        dfs(image, i - 1, j, val, color);
        dfs(image, i, j + 1, val, color);
        dfs(image, i + 1, j, val, color);
        dfs(image, i, j - 1, val, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int val = image[sr][sc];
        if (val == color)
            return image;
        dfs(image, sr, sc, val, color);
        return image;
    }
};