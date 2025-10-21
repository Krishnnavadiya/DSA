#include <bits/stdc++.h>
using namespace std;

// 2011. Final Value of Variable After Performing Operations

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans = 0;
        for (string x : operations)
            ans += (x[1] == '+' ? 1 : -1);
        return ans;
    }
};

int main()
{
    vector<string> operations = {"--X", "X++", "X++"};
    Solution sol;
    cout << sol.finalValueAfterOperations(operations);
    return 0;
}