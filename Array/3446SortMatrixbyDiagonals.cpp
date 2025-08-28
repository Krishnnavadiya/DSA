#include <bits/stdc++.h>
using namespace std;

// 3446. Sort Matrix by Diagonals

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
       int n = grid.size(), m = grid[0].size();
        unordered_map<int, priority_queue<int>> maxHeaps;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
            minHeaps;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0)
                    minHeaps[key].push(grid[i][j]);
                else
                    maxHeaps[key].push(grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = i - j;
                if (key < 0) {
                    grid[i][j] = minHeaps[key].top();
                    minHeaps[key].pop();
                } else {
                    grid[i][j] = maxHeaps[key].top();
                    maxHeaps[key].pop();
                }
            }
        }
        return grid;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    Solution sol;
    vector<vector<int>> result = sol.sortMatrix(grid);

    for (const auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
