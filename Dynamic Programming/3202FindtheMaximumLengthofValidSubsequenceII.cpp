#include <bits/stdc++.h>
using namespace std;

// 3202. Find the Maximum Length of Valid Subsequence II

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int res = 2;
        for (int j = 0; j < k; ++j)
        {
            vector<int> dp(k, 0);
            for (int i = 0; i < nums.size(); ++i)
            {
                int mod = nums[i] % k;
                int pos = (j - mod + k) % k;
                dp[mod] = dp[pos] + 1;
            }

            for (int val : dp)
            {
                res = max(res, val);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;
    int result = sol.maximumLength(nums, k);
    cout << "Maximum Length: " << result << endl;
    return 0;
}