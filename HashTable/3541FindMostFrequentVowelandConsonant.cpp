#include <bits/stdc++.h>
using namespace std;

// 3541. Find Most Frequent Vowel and Consonant

class Solution
{
public:
    int maxFreqSum(string s)
    {
        map<char, int> vo, co;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vo[ch]++;
            }
            else
            {
                co[ch]++;
            }
        }

        int maxVowelFreq = 0, maxConsonantFreq = 0;

        if (!vo.empty())
        {
            auto maxVowel = max_element(vo.begin(), vo.end(),
                                        [](const auto &p1, const auto &p2)
                                        {
                                            return p1.second < p2.second;
                                        });
            maxVowelFreq = maxVowel->second;
        }

        if (!co.empty())
        {
            auto maxConsonant = max_element(co.begin(), co.end(),
                                            [](const auto &p1, const auto &p2)
                                            {
                                                return p1.second < p2.second;
                                            });
            maxConsonantFreq = maxConsonant->second;
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxFreqSum("successes") << endl;
    cout << sol.maxFreqSum("aeiaeia") << endl;
    return 0;
}
