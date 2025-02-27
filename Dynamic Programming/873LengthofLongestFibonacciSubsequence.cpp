#include <bits/stdc++.h>
using namespace std;

// 873. Length of Longest Fibonacci Subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> indexMap;
        unordered_map<int, int> dp;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int prev = arr[i] - arr[j];
                
                if (indexMap.count(prev) && indexMap[prev] < j) {
                    int k = indexMap[prev];
                    int currLength = dp[k * n + j] + 1;
                    dp[j * n + i] = max(3, currLength);
                    maxLength = max(maxLength, dp[j * n + i]);
                } else {
                    dp[j * n + i] = 2;
                }
            }
        }

        return (maxLength >= 3) ? maxLength : 0;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << sol.lenLongestFibSubseq(arr) << endl;
    return 0;
}
