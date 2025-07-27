#include <bits/stdc++.h>
using namespace std;

// 2210. Count Hills and Valleys in an Array

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        // unordered_set<int> result;
        // int count = 0;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     result.insert(nums[i]);
        // }

        vector<int> result;
        int count = 0;
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                result.push_back(nums[i]);
            }
        }

        for (int i = 1; i < result.size() - 1; ++i)
        {
            if (result[i] > result[i + 1] && result[i] > result[i - 1])
            {
                count++;
            }
            else if (result[i] < result[i + 1] && result[i] < result[i - 1])
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    Solution sol;
    cout << sol.countHillValley(nums);
    return 0;
}