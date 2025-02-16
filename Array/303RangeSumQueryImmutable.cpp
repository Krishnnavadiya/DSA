#include <bits/stdc++.h>
using namespace std;

// 303. Range Sum Query - Immutable

class NumArray
{
    vector<int> vc;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        vc.resize(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            vc[i + 1] = vc[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return vc[right + 1] - vc[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl; 
    cout << numArray.sumRange(0, 5) << endl; 

    return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */