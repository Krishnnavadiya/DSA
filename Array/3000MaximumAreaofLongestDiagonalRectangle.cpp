#include <bits/stdc++.h>
using namespace std;

// 3000. Maximum Area of Longest Diagonal Rectangle

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int num1 = 0, num2 = 0;
        long long max_num = LLONG_MIN;

        for (int i = 0; i < dimensions.size(); i++)
        {
            long long cal = 1LL * dimensions[i][0] * dimensions[i][0] +
                            1LL * dimensions[i][1] * dimensions[i][1];
            if (cal > max_num || (cal == max_num && num1 * num2 < dimensions[i][0] * dimensions[i][1]))
            {
                max_num = cal;
                num1 = dimensions[i][0];
                num2 = dimensions[i][1];
            }
        }
        return num1 * num2;
    }
};

int main()
{
    vector<vector<int>> dimenstions = {{9, 3}, {8, 6}};
    Solution sol;
    cout << sol.areaOfMaxDiagonal(dimenstions);
    return 0;
}