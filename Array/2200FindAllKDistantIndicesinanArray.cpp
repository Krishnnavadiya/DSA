#include <bits/stdc++.h>
using namespace std;

// 2200. Find All K-Distant Indices in an Array

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        vector<int> isDistant(n, false);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
            {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j)
                {
                    isDistant[j] = true;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (isDistant[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 5, 9, 1, 3, 9, 5};
    int key = 9, k = 1;
    vector<int> result = sol.findKDistantIndices(nums, key, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}