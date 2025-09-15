#include <bits/stdc++.h>
using namespace std;

// 1935. Maximum Number of Words You Can Type

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        set<char> s(brokenLetters.begin(), brokenLetters.end());

        int counter = 0;
        bool canType = true;
        for (int i = 0; i < text.size(); i++)
        {
            if (s.count(text[i]) > 0)
            {
                canType = false;
            }
            if ((text[i] == ' ' || i == text.size() - 1))
            {
                if (canType)
                    counter++;
                canType = true;
            }
        }
        return counter;
    }
};

int main()
{
    Solution sol;
    cout << sol.canBeTypedWords("leet code", "ad");
    return 0;
}