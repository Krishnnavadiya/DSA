#include <bits/stdc++.h>
using namespace std;

// 137. Single Number II

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
       int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {0,1,0,1,0,1,99};

    int single = sol.singleNumber(nums);

    cout << "The single number is: " << single << endl;

    return 0;
}
