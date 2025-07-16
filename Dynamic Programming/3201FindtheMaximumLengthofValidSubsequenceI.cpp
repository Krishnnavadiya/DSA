#include <bits/stdc++.h>
using namespace std;

// 3201. Find the Maximum Length of Valid Subsequence I

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int count_even = 0, count_odd = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
                count_even++;
            else
                count_odd++;
        }

        int even_dp = 0, odd_dp = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
                even_dp = max(even_dp, odd_dp + 1);
            else
                odd_dp = max(odd_dp, even_dp + 1);
        }

        return max({count_even, count_odd, even_dp, odd_dp});
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int result = sol.maximumLength(nums);
    cout << "Maximum Length: " << result << endl;
    return 0;
}