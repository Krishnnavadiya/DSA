#include <bits/stdc++.h>
using namespace std;

//1752. Check if Array Is Sorted and Rotated

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                cnt++;
            }
        }
        return cnt <= 1;
    }
};

int main()
{
    Solution sol;
    vector nums = {3, 4, 5, 1, 2};
    bool result = sol.check(nums);
    cout << result;
    return 0;
}