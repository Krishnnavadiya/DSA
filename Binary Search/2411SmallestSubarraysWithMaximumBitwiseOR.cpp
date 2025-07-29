#include <bits/stdc++.h>
using namespace std;

// 2411. Smallest Subarrays With Maximum Bitwise OR

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 0; i < len; ++i)
        {
            int x = nums[i];
            res[i] = 1;
            int j = i - 1;
            while (j >= 0 && (nums[j] | x) != nums[j])
            {
                res[j] = i - j + 1;
                nums[j] |= x;
                --j;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 0, 2, 1, 3};
    Solution sol;
    vector<int> result = sol.smallestSubarrays(nums);

    cout << "Result: ";
    for (int len : result)
    {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}