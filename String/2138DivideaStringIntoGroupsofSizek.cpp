#include <bits/stdc++.h>
using namespace std;

// 2138. Divide a String Into Groups of Size k

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> result;
        if (s.length() % k != 0)
        {
            s.append(k - (s.length() % k), fill);
        }
        for (int i = 0; i < s.length(); i = i + k)
        {
            result.push_back(s.substr(i, k));
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string str = "abcdefg";
    int k = 3;
    char fill = 'x';
    vector<string> result = sol.divideString(str, k, fill);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}