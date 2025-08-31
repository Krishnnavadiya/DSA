#include <bits/stdc++.h>
using namespace std;

// 3021. Alice and Bob Playing Flower Game

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        return 1LL * ((n + 1) / 2) * (m / 2) + 1LL * (n / 2) * ((m + 1) / 2);
    }
};

int main()
{
    Solution sol;
    cout << sol.flowerGame(3, 2);
    return 0;
}