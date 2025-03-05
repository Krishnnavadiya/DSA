#include <bits/stdc++.h>
using namespace std;

// 2579. Count Total Number of Colored Cells

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long result = pow(n, 2) + pow(n - 1, 2);
        return result;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout <<sol.coloredCells(n) << endl;

    return 0;
}