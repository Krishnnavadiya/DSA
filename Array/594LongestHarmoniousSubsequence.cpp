#include <bits/stdc++.h>
using namespace std;

// 594. Longest Harmonious Subsequence

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int maxVal = 0;
        unordered_map<int, int> mp;
        for (int value : nums)
        {
            mp[value]++;
        }
        for (auto &[num, count] : mp)
        {
            if (mp.find(num + 1) != mp.end())
            {
                maxVal = max(maxVal, mp[num] + mp[num + 1]);
            }
        }
        return maxVal;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    Solution sol;
    cout << sol.findLHS(nums);
}