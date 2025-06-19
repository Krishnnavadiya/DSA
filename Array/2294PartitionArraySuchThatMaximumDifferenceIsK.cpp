#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int i = 0, count = 1;
        sort(nums.begin(), nums.end());
        for (int j = 1; j < nums.size(); j++)
        {
            if ((nums[j] - nums[i]) > k)
            {
                i = j;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 4, 5};
    int k = 0;
    int totalPartition = sol.partitionArray(nums, k);
    cout << totalPartition << endl;
}