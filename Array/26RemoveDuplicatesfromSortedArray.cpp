#include <bits/stdc++.h>
using namespace std;

//26. Remove Duplicates from Sorted Array

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /* Brute Force
        set<int> final;
        for (int i = 0; i < nums.size(); i++)
        {
            final.insert(nums[i]);
        }
        return final.size();
        */

        // Optimal
        int first = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[first]!=nums[i]){
                nums[first+1]=nums[i];
                first++;
            }
        }
        return first+1;
    }
};

int main()
{
    Solution sol;
    vector nums = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5};
    int uniqueEle = sol.removeDuplicates(nums);
    cout << uniqueEle << endl;
    return 0;
}