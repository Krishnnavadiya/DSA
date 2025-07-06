#include <bits/stdc++.h>
using namespace std;

// 198. House Robber

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    cout << sol.rob(nums);
    return 0;
}