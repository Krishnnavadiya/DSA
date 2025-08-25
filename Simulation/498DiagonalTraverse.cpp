#include <bits/stdc++.h>
using namespace std;

// 498. Diagonal Traverse

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> result;
        map<int, vector<int>> mp;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto &it : mp)
        {
            if (flip == true)
            {
                reverse(it.second.begin(), it.second.end());
            }

            for (int &num : it.second)
            {
                result.push_back(num);
            }
            flip = !flip;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    vector<int> result = sol.findDiagonalOrder(mat);
    for (int i : result)
    {
        cout << i;
    }

    return 0;
}