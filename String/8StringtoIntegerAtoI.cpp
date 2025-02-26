#include <bits/stdc++.h>
using namespace std;

//8. String to Integer (atoi)

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        long long number = 0;
        bool negative = false;

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            negative = (s[i] == '-');
            i++;
        }

        while (i < n && isdigit(s[i]))
        {
            number = number * 10 + (s[i] - '0');

            if (number > INT_MAX)
            {
                return negative ? INT_MIN : INT_MAX;
            }
            i++;
        }

        return negative ? -number : number;
    }
};

int main()
{
    Solution sol;
    string x;

    cout << "Enter a String: ";
    cin >> x;

    cout << sol.myAtoi(x);
    return 0;
}
