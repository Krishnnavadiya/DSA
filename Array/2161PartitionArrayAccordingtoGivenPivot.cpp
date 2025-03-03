#include <bits/stdc++.h>
using namespace std;

// 2161. Partition Array According to Given Pivot

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int lCount = 0;
        int gCount = 0;
        int pCount = 0;
        for (int num : nums)
        {
            if (num < pivot)
            {
                lCount++;
            }
            else if (num > pivot)
            {
                gCount++;
            }
            else
            {
                pCount++;
            }
        }
        int i = 0;
        int j = lCount;
        int k = lCount + pCount;
        vector<int> res(nums.size());
        for (int num : nums)
        {
            if (num < pivot)
            {
                res[i] = num;
                i++;
            }
            else if (num > pivot)
            {
                res[k] = num;
                k++;
            }
            else
            {
                res[j] = num;
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10}; 
    int pivot = 10;                              

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Partitioned Array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}