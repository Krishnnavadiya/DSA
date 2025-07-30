#include <bits/stdc++.h>
using namespace std;

// 2419. Longest Subarray With Maximum Bitwise AND

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxnum = INT64_MIN, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxnum = max(maxnum, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxnum)
            {
                count++;
            }
        }
        return count;

        /*
        int maxnum = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currLen = 0;

        for (int num : nums)
        {
            if (num == maxnum)
            {
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else
            {
                currLen = 0;
            }
        }
        return maxLen;
        */
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    Solution sol;
    cout << sol.longestSubarray(nums);
    return 0;
}