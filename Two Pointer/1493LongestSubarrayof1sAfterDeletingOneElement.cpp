#include <bits/stdc++.h>
using namespace std;

// 1493. Longest Subarray of 1's After Deleting One Element

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int preZero = 0, current = 0, best = 0;
        bool hasZero = false;

        for (int num : nums)
        {
            if (num == 0)
            {
                preZero = current;
                current = 0;
                hasZero = true;
            }
            else
            {
                current++;
            }
            best = max(best, preZero + current);
        }

        return hasZero ? best : (int)nums.size() - 1;
    }
};

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    Solution sol;
    cout << sol.longestSubarray(nums);
    return 0;
}