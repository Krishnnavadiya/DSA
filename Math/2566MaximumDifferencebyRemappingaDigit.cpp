#include <bits/stdc++.h>
using namespace std;

// 2566. Maximum Difference by Remapping a Digit

class Solution
{
public:
    int minMaxDifference(int num)
    {
        char cchar;
        string str = to_string(num), finalmax, finalmin;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '9')
            {
                cchar = str[i];
                break;
            }
        }
        for (char c : str)
        {
            if (c == cchar)
                finalmax = finalmax + '9';
            else
                finalmax = finalmax + c;
        }
        cchar = str[0];
        for (char c : str)
        {
            if (c == cchar)
                finalmin = finalmin + '0';
            else
                finalmin = finalmin + c;
        }
        return stoi(finalmax) - stoi(finalmin);
    }
};

int main()
{
    Solution sol;

    int nums = 90;

    int single = sol.minMaxDifference(nums);

    cout << single << endl;

    return 0;
}