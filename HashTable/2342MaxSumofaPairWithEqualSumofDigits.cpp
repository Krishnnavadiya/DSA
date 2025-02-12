#include <bits/stdc++.h>
using namespace std;

int digitSum(int digit)
{
    int sum = 0;
    while (digit != 0)
    {
        sum += digit % 10;
        digit /= 10;
    }
    return sum;
}

int maximumSum(vector<int> &nums)
{
    int maxSum=-1;
    map<int, int> digit;
    for (int n : nums)
    {
        int key = digitSum(n);
        if (digit.count(key) > 0)
        {
            maxSum = max(maxSum, digit[key] + n);
        }
        digit[key] = max(digit[key], n);
    }
    return maxSum;
}

int main()
{
    vector<int> vc = {18,43,36,13,7};
    cout << maximumSum(vc);
}