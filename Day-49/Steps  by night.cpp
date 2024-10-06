#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int n = N;
    int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
    int x1 = KnightPos[0] - 1, y1 = KnightPos[1] - 1;

    if (tx == x1 && ty == y1)
        return 0;

    queue<pair<int, int>> q;
    q.push({x1, y1});

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[x1][y1] = true;

    int x[8] = {1, 1, -1, -1, 2, -2, 2, -2};
    int y[8] = {2, -2, 2, -2, 1, 1, -1, -1};

    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        ans++;

        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            q.pop();

            int xx = p.first;
            int yy = p.second;

            for (int i = 0; i < 8; i++)
            {
                int xaxis = xx + x[i];
                int yaxis = yy + y[i];

                if (xaxis == tx && yaxis == ty)
                    return ans;

                if (xaxis >= 0 && xaxis < n && yaxis >= 0 && yaxis < n && !visited[xaxis][yaxis])
                {
                    q.push({xaxis, yaxis});
                    visited[xaxis][yaxis] = true;
                }
            }
        }
    }
    return -1; // If the target is unreachable
}
