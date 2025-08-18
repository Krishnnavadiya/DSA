#include <bits/stdc++.h>
using namespace std;

// 1323. Maximum 69 Number

class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main()
{
    int num = 9699;
    Solution sol;
    cout << sol.maximum69Number(num);
    return 0;
}