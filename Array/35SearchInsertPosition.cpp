#include <bits/stdc++.h>
using namespace std;

// 35. Search Insert Position

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < target)
            {
                result = i + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index = sol.searchInsert(nums, target);
    cout << "The target " << target << " should be at index: " << index << endl;

    return 0;
}