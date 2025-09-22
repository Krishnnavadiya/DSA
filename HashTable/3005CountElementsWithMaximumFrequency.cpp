#include <bits/stdc++.h>
using namespace std;

// 3005. Count Elements With Maximum Frequency

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        int max_freq = 0;
        for (auto &p : freq)
        {
            max_freq = max(max_freq, p.second);
        }
        int result = 0;
        for (auto &p : freq)
        {
            if (max_freq == p.second)
            {
                result += p.second;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2, 1, 4};
    Solution sol;
    cout << sol.maxFrequencyElements(nums);
    return 0;
}