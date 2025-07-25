#include <bits/stdc++.h>
using namespace std;

// 3487. Maximum Unique Subarray Sum After Deletion

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int sum = 0;
        set<int> st;
        int mxNeg = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                st.insert(nums[i]);
            else
                mxNeg = max(mxNeg, nums[i]);
        }
        for (auto val : st)
        {
            sum += val;
        }
        if (st.size())
            return sum;
        else
            return mxNeg;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, -1, -5};
    vector<int> nums2 = {-3, -7, -1};
    vector<int> nums3 = {5, 5, 5, 5};

    cout << "Max Sum (nums1): " << sol.maxSum(nums1) << endl; // Output: 6 (1 + 2 + 3)
    cout << "Max Sum (nums2): " << sol.maxSum(nums2) << endl; // Output: -1 (max negative)
    cout << "Max Sum (nums3): " << sol.maxSum(nums3) << endl; // Output: 5 (unique set {5})

    return 0;
}