#include <bits/stdc++.h>
using namespace std;

//283. Move Zeroes

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = -1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                i = j;
                break;
            }
        }
        if (i == -1)
            return;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 2, 4, 3, 0, 4, 3, 0, 0, 6, 7, 9, 5, 0};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}