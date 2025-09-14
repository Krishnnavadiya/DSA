#include <bits/stdc++.h>
using namespace std;

// 966. Vowel Spellchecker

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exactMatchSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelInsensitiveMap;

        auto normalizeVowels = [](const string &word)
        {
            string res = word;
            for (char &c : res)
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    c = '*';
                }
            }
            return res;
        };

        for (string &word : wordlist)
        {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            if (!caseInsensitiveMap.count(lowerWord))
            {
                caseInsensitiveMap[lowerWord] = word;
            }

            string vowelNormalized = normalizeVowels(lowerWord);
            if (!vowelInsensitiveMap.count(vowelNormalized))
            {
                vowelInsensitiveMap[vowelNormalized] = word;
            }
        }

        vector<string> results;
        for (string &query : queries)
        {
            if (exactMatchSet.count(query))
            {
                results.push_back(query);
                continue;
            }

            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
            if (caseInsensitiveMap.count(lowerQuery))
            {
                results.push_back(caseInsensitiveMap[lowerQuery]);
                continue;
            }

            string vowelNormalized = normalizeVowels(lowerQuery);
            if (vowelInsensitiveMap.count(vowelNormalized))
            {
                results.push_back(vowelInsensitiveMap[vowelNormalized]);
                continue;
            }

            results.push_back("");
        }
        return results;
    }
};

int main()
{
    Solution sol;
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> results = sol.spellchecker(wordlist, queries);

    for (const string &res : results)
    {
        cout << (res.empty() ? "''" : res) << endl;
    }

    return 0;
}
