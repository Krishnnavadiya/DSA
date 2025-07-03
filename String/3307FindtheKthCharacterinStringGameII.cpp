#include <bits/stdc++.h>
using namespace std;

// 3307. Find the K-th Character in String Game II

class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        /* Brute Force
        string word = "a";
        int i = 0;
        while (word.length() < k)
        {
            string temp = "";
            if (operations[i] == 0)
            {
                word = word + word;
            }
            else
            {
                for (char i : word)
                {
                    if (i != 'z')
                        temp.push_back(i + 1);
                    else
                        temp.push_back('a');
                }
                word += temp;
            }
            i++;
        }
        return word[k-1];
        */

        // Optimal
        int ct = 0;
        while(k > 1){
            long long lg = log2(k);
            long long po = pow(2,lg);
            long long opers = po == k ? lg : lg + 1;
            if(operations[opers - 1] == 1)ct++;
            long long ln = pow(2,opers - 1);
            k -= ln; 
        }
        return 'a' + (ct%26);
    }
};

int main()
{
    vector<int> operations = {1, 1, 1, 1};
    Solution sol;
    cout << sol.kthCharacter(12, operations);
    return 0;
}