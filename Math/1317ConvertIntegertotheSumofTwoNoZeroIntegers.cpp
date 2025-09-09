#include <bits/stdc++.h>
using namespace std;

// 1317. Convert Integer to the Sum of Two No-Zero Integers

class Solution
{
public:
    bool hasZero(int x)
    {
        while (x > 0)
        {
            if (x % 10 == 0)
                return true;
            x /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n)
    {
        for (int a = 1; a < n; a++)
        {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b))
            {
                return {a, b};
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.getNoZeroIntegers(2);
    return 0;
}