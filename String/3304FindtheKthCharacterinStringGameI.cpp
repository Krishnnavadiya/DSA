#include <bits/stdc++.h>
using namespace std;

// 3304. Find the K-th Character in String Game I

class Solution
{
public:
    char kthCharacter(int k)
    {
        /* Brute Force
        string word = "a";
        while (word.length() < k) {
            if (word.length() / 2 > 0) {
                string str = word.substr(word.length() / 2);
                word.append(word, word.length() / 2, word.length());

                for (int i = 0; i < str.length(); i++) {
                    word += str[i] + 1;
                }
            } else {
                word += word[0] + 1;
            }
        }

        cout << word << endl;
        return word[k - 1];
        */

        // optimal
        char word = 'a';

        int n = k - 1;
        int count = 0;
        while (n > 0) // Count the number of set bits
        {
            n &= (n - 1);
            count++;
        }
        return word + count;
    }
};

int main()
{
    Solution sol;
    cout << sol.kthCharacter(12);
}