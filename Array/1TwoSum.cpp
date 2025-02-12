#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int positioni,positionj;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if((nums[i]+nums[j])==target){
                positioni=i;
                positionj=j;
                break;
            }
        }
    }
    return {positioni,positionj};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}