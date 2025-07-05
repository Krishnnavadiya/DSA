#include <bits/stdc++.h>
using namespace std;

// 410. Split Array Largest Sum

class Solution
{
public:
    int noOfStudents(vector<int> &nums, int pages)
    {
        int student = 1;
        int pagesum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pagesum + nums[i] <= pages)
            {
                pagesum += nums[i];
            }
            else
            {
                student++;
                pagesum = nums[i];
            }
        }
        return student;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int student = noOfStudents(nums, mid);
            if (student <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    vector<int> nums = {2, 2, 3};
    int k = 2;
    Solution sol;
    cout << sol.splitArray(nums, k);
    return 0;
}