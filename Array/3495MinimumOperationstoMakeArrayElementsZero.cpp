#include <bits/stdc++.h>
using namespace std;

// 3495. Minimum Operations to Make Array Elements Zero

class Solution {
public:

    long long fn(int num){
        if(num<=0)return 0;
        if(num<=3)return num;
        int cnt=2;
        int pre=3;
        long long ans=3;
        for(int i=4;i<=num;i*=4){
            long long upper=1LL*i*4-1;
            long long range=0;
            if(upper>=num){
                range=num-pre;
            }else{
                range=upper-pre;
            }
            pre=upper;
            ans+=(1LL*range*cnt);
            cnt++;
        }
        return ans;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;

        for(auto q:queries){
            int left=q[0],right=q[1];

            long long val1=fn(right);
            long long val2=fn(left-1);
            long long diff=val1-val2;
            if(diff%2)diff++;
            ans+=(diff/2);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> queries = {
        {1, 3},
        {2, 5},
        {4, 7}
    };

    Solution sol;
    cout << sol.minOperations(queries) << "\n";

    return 0;
}