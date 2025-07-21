#include <bits/stdc++.h>
using namespace std;

// 1957. Delete Characters to Make Fancy String

class Solution
{
public:
    string makeFancyString(string s)
    {
        string result;
        int count = 1;

        result += s[0];

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;

            if (count < 3)
                result += s[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "leeetcode";
    cout << sol.makeFancyString(s);
    return 0;
}