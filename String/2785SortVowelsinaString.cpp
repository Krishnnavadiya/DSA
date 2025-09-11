#include <bits/stdc++.h>
using namespace std;

// 2785. Sort Vowels in a String

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> vowel;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U')
            {
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(), vowel.end());
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U')
            {
                s[i] = vowel[j];
                j++;
            }
        }
        return s;
    }
};

int main()
{
    string s = "leetcode";
    Solution sol;
    cout << sol.sortVowels("leetcode");
    return 0;
}