#include <bits/stdc++.h>
using namespace std;

// 2197. Replace Non-Coprime Numbers in Array

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> result;
        for (int num : nums)
        {
            result.push_back(num);
            while (result.size() > 1)
            {
                int a = result.back();
                int b = result[result.size() - 2];
                int g = gcd(a, b);
                if (g > 1)
                {
                    result.pop_back();
                    result.pop_back();
                    long long lcm = (long long)a / g * b;
                    result.push_back((int)lcm);
                }
                else
                {
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    Solution sol;
    vector<int> result = sol.replaceNonCoprimes(nums);
    for (int i : result)
        cout << i << " ";
    return 0;
}