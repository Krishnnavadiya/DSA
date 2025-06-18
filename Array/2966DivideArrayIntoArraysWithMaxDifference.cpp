#include <bits/stdc++.h>
using namespace std;

//2966. Divide Array Into Arrays With Max Difference

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> final;
        for (int i = 2; i < nums.size(); i+=3)
        {
            if ((nums[i] - nums[i - 2]) <= k)
                final.push_back({nums[i-2],nums[i-1],nums[i]});
            else
                return {};
        }
        return final;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    vector<vector<int>> result = sol.divideArray(nums, k);
    if (result.empty())
    {
        cout << "[]\n";
    }
    else
    {
        for (const auto &group : result)
        {
            cout << "[";
            for (int i = 0; i < group.size(); ++i)
            {
                cout << group[i];
                if (i < group.size() - 1)
                    cout << ",";
            }
            cout << "] ";
        }
        cout << "\n";
    }
}