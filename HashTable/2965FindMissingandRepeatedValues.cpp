#include <bits/stdc++.h>
using namespace std;

// 2965. Find Missing and Repeated Values

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int repeating, missing;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curr = abs(grid[i][j]);
                int row = (curr - 1) / n;
                int col = (curr - 1) % n;
                if (grid[row][col] < 0)
                {
                    repeating = abs(curr);
                    continue;
                }
                grid[row][col] *= (-1);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                {
                    missing = i * n + (j + 1);
                    break;
                }
            }
        }
        return {repeating, missing};
    }
};

int main()
{
    vector<vector<int>> arr = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    Solution sol;
    vector<int> result = sol.findMissingAndRepeatedValues(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}