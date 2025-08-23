#include <bits/stdc++.h>
using namespace std;

// 189. Rotate Array

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main()
{
    Solution sol;
    vector nums = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5};
    int k = 3;
    sol.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}