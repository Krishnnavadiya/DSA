#include <bits/stdc++.h>
using namespace std;

// 2042. Check if Numbers Are Ascending in a Sentence

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int oneNumber = -1;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            if (isdigit(word[0]))
            {
                if (stoi(word) <= oneNumber)
                {
                    return false;
                }
                oneNumber = stoi(word);
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string x;

    cout << "Enter a String: ";
    getline(cin, x);

    cout << (sol.areNumbersAscending(x) ? "true" : "false");
    return 0;
}