#include <bits/stdc++.h>
using namespace std;

// 1733. Minimum Number of People to Teach

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages,
                         vector<vector<int>> &friendships)
    {
        int m = languages.size();
        vector<unordered_set<int>> knows(m + 1);

        for (int i = 0; i < m; i++)
        {
            for (int lang : languages[i])
            {
                knows[i + 1].insert(lang);
            }
        }

        unordered_set<int> needTeach;
        for (auto &f : friendships)
        {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int lang : knows[u])
            {
                if (knows[v].count(lang))
                {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk)
            {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        if (needTeach.empty())
            return 0;

        vector<int> freq(n + 1, 0);
        for (int person : needTeach)
        {
            for (int lang : knows[person])
            {
                freq[lang]++;
            }
        }

        int maxValue = *max_element(freq.begin(), freq.end());

        return (int)needTeach.size() - maxValue;
    }
};

int main()
{
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
    Solution sol;
    cout << sol.minimumTeachings(n, languages, friendships);
    return 0;
}