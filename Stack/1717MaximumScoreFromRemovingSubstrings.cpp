#include <bits/stdc++.h>
using namespace std;

// 1717. Maximum Score From Removing Substrings

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int score = 0;
        char ch1 = 'a', ch2 = 'b';
        int cnt1 = 0, cnt2 = 0;

        if (x < y)
        {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }

        for (char ch : s)
        {
            if (ch == ch1)
            {
                cnt1++;
            }
            else if (ch == ch2)
            {
                if (cnt1 > 0)
                {
                    cnt1--;
                    score += x;
                }
                else
                {
                    cnt2++;
                }
            }
            else
            {
                score += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        if (cnt1 != 0)
        {
            score += min(cnt1, cnt2) * y;
        }

        return score;
    }
};

int main()
{
    Solution sol;

    string s = "cdbcbbaaabab";
    int x = 4; // Gain for removing "ab"
    int y = 5; // Gain for removing "ba"

    int result = sol.maximumGain(s, x, y);
    cout << "Maximum Gain: " << result << endl;

    return 0;
}