#include <bits/stdc++.h>
using namespace std;

// 1695. Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int currSum = 0, sum = 0;
        int left = 0, right = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                ++left;
            }
            seen.insert(nums[right]);
            currSum += nums[right];
            sum = max(sum, currSum);
        }
        return sum;
    }
};

int main()
{
    vector<int> nums = {187, 470, 25, 436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411, 459, 490, 266, 987, 965, 429, 166, 809, 340, 467, 318, 125, 165, 809, 610, 31, 585, 970, 306, 42, 189, 169, 743, 78, 810, 70, 382, 367, 490, 787, 670, 476, 278, 775, 673, 299, 19, 893, 817, 971, 458, 409, 886, 434};
    Solution sol;
    cout << sol.maximumUniqueSubarray(nums);
    return 0;
}