#include <bits/stdc++.h>
using namespace std;

// 3330. Find the Original Typed String I

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int count = 1;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.possibleStringCount("abbcccc");
}