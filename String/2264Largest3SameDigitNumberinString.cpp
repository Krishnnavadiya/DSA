#include <bits/stdc++.h>
using namespace std;

// 2264. Largest 3-Same-Digit Number in String

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string best;
        char current = num[0];
        int count = 0;
        for (char c : num)
        {
            if (current == c)
            {
                ++count;
            }
            else
            {
                current = c;
                count = 1;
            }
            if (count == 3)
            {
                string triplet(3, current);
                if (triplet > best)
                    best = triplet;
            }
        }
        return best;
    }
};

int main()
{
    string num = "6777133339";
    Solution sol;
    cout << sol.largestGoodInteger(num);
    return 0;
}