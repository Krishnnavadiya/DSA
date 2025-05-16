#include <bits/stdc++.h>
using namespace std;

// 34. Find First and Last Position of Element in Sorted Array

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result = {-1, -1};
        bool firstFlag = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target && firstFlag)
            {
                result[0] = i;
                firstFlag = false;
            }
            if (nums[i] == target && !firstFlag)
            {
                result[1] = i;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First and Last Position of " << target << ": ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
