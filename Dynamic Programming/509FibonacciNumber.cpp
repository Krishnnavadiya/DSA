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

    int fibo(int n, unordered_map<int, int> mp)
    {
        if (n <= 1)
        {
            return n;
        }
        if (mp.find(n) != mp.end())
        {
            return mp[n];
        }
        int a = fibo(n - 1, mp);
        int b = fibo(n - 2, mp);
        mp[n] = a + b;
        return mp[n];
    }
};

int main()
{
    unordered_map<int, int> mp;
    Solution sol;
    cout << sol.fibo(10,mp);
}