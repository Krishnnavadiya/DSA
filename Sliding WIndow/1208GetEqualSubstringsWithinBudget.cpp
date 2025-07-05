#include <bits/stdc++.h>
using namespace std;

// 1208. Get Equal Substrings Within Budget

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int start = 0, end = 0, maxLength = 0, cost = 0;
        while (end < s.size())
        {
            cost += abs(s[end] - t[end]);

            while (cost > maxCost)
            {
                cost -= abs(s[start] - t[start]);
                ++start;
            }
            maxLength = max(maxLength, end - start + 1);
            ++end;
        }
        return maxLength;
    }
};

int main()
{
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    Solution sol;
    cout << sol.equalSubstring(s, t, maxCost);
    return 0;
}