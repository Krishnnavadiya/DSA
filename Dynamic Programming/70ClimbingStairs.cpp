#include <bits/stdc++.h>
using namespace std;

// 70. Climbing Stairs

class Solution {
public:
    // Dynamic Programming
    int climbStairs(int n, unordered_map<int, int>& mp) {
        if (n <= 2) {
            return n;
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }

        mp[n] = climbStairs(n - 1, mp) + climbStairs(n - 2, mp);
        return mp[n];
    }

    // Helper function to start with an empty map
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return climbStairs(n, mp);
    }
    /* Recursion
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    */
};

int main()
{
    unordered_map<int, int> mp;
    Solution sol;
    cout << sol.climbStairs(5, mp);
    return 0;
}