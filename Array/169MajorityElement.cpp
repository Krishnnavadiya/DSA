#include <bits/stdc++.h>
using namespace std;

// 169. Majority Element

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.majorityElement(nums);
    return 0;
}