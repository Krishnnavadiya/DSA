#include <bits/stdc++.h>
using namespace std;

// 509. Fibonacci Number

class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main()
{
    Solution sol;
    cout << sol.fib(10);
}