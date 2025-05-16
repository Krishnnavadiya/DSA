#include <bits/stdc++.h>
using namespace std;

// 136. Single Number

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int first = 0, second = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[first] != nums[second])
            {
                return nums[first];
            }
            else
            {
                first += 2;
                second += 2;
            }
        }
        return nums[nums.size() - 1];
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {4, 1, 2, 1, 2};

    int single = sol.singleNumber(nums);

    cout << "The single number is: " << single << endl;

    return 0;
}
