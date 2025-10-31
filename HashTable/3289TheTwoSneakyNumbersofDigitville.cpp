#include <bits/stdc++.h>
using namespace std;

// 3289. The Two Sneaky Numbers of Digitville

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        vector<int> result;
        for (int i : nums)
        {
            freq[i]++;
        }
        for (auto &p : freq)
        {
            if (p.second == 2)
                result.push_back(p.first);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    vector<int> answer = sol.getSneakyNumbers(nums);
    for (int i : answer)
    {
        cout << i << " ";
    }
}