#include <bits/stdc++.h>
using namespace std;

// 3136. Valid Word

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;

        bool hasVowel = false, hasConsonant = false;

        for (char c : word)
        {
            if (isdigit(c))
                continue;

            if (isalpha(c))
            {
                char lowerC = tolower(c);
                if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
            else
            {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};

int main()
{
    string word = "234Adas";
    Solution sol;
    cout << sol.isValid(word);
    return 0;
}