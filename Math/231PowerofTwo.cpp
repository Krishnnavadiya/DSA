#include <bits/stdc++.h>
using namespace std;

// 231. Power of Two

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.isPowerOfTwo(n);
    return 0;
}