#include <bits/stdc++.h>
using namespace std;

// 2016. Maximum Difference Between Increasing Elements

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int min = nums[0];
        int maxDiff = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > min)
                maxDiff = max(maxDiff, (nums[i] - min));
            else
                min = nums[i];
        }
        return maxDiff;
    }
};

int main()
{
    Solution sol;

    vector nums = {87, 68, 91, 86, 58, 63, 43, 98, 6, 40};

    int single = sol.maximumDifference(nums);

    cout << single << endl;

    return 0;
}