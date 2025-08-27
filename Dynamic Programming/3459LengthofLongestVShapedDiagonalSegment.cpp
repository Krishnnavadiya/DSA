#include <bits/stdc++.h>
using namespace std;

// 3459. Length of Longest V-Shaped Diagonal Segment

class Solution
{
public:
    vector<vector<int>> DIRS = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(1 << 3, 0)));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 1)
                    continue;
                vector<int> maxs = {m - i, j + 1, i + 1, n - j};
                for (int k = 0; k < 4; k++)
                {
                    if (maxs[k] > ans)
                    {
                        ans = max(ans, dfs(i, j, k, 1, 2, grid, memo) + 1);
                    }
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, int k, int canTurn, int step,
            vector<vector<int>> &grid,
            vector<vector<vector<int>>> &memo)
    {
        i += DIRS[k][0];
        j += DIRS[k][1];

        int expected = (step % 2 == 0 ? 2 : 0);

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != expected)
        {
            return 0;
        }

        int mask = (k << 1) | canTurn;
        if (memo[i][j][mask] > 0)
            return memo[i][j][mask];

        int res = dfs(i, j, k, canTurn, step + 1, grid, memo);

        if (canTurn == 1)
        {
            int nk = (k + 1) % 4;
            res = max(res, dfs(i, j, nk, 0, step + 1, grid, memo));
        }

        return memo[i][j][mask] = res + 1;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    Solution sol;
    cout << sol.lenOfVDiagonal(grid);
    return 0;
}