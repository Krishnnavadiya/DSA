#include <bits/stdc++.h>
using namespace std;

// 961. N-Repeated Element in Size 2N Array

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int x : nums)
        {
            if (seen.count(x))
                return x;
            seen.insert(x);
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 3};
    cout << sol.repeatedNTimes(nums);
    return 0;
}