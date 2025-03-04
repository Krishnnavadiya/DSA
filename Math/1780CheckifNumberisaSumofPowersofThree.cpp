#include <bits/stdc++.h>
using namespace std;

// 1780. Check if Number is a Sum of Powers of Three

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n = n / 3;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << (sol.checkPowersOfThree(n) ? "true" : "false");
    return 0;
}