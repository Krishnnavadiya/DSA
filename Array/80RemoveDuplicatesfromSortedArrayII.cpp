#include <bits/stdc++.h>
using namespace std;

// 80. Remove Duplicates from Sorted Array II

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0, r = 0;
        while (r < nums.size())
        {
            int count = 1;
            while (r + 1 < nums.size() && nums[r] == nums[r + 1])
            {
                r++;
                count++;
            }
            int cnum = min(2, count);
            for (int i = 0; i < cnum; i++)
            {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 5};
    Solution sol;
    cout << sol.removeDuplicates(nums);
    return 0;
}