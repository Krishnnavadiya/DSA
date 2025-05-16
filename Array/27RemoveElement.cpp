#include <bits/stdc++.h>
using namespace std;

// 27. Remove Element

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int first = 0, second = nums.size() - 1;
        int length = nums.size();
        while (second >= first)
        {
            if (nums[second] == val)
            {
                length--;
                second--;
            }else{
                if(nums[first] != val){
                    first++;
                }
                else{
                    swap(nums[first],nums[second]);
                    second--;
                    length--;
                }
            }
        }
        return length;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int newLength = sol.removeElement(nums, val);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}