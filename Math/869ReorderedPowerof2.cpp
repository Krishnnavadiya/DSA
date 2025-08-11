#include <bits/stdc++.h>
using namespace std;

// 869. Reordered Power of 2

class Solution
{
public:
    unordered_set<string> st;
    void buildset()
    {
        for (int i = 0; i <= 29; i++)
        {
            string s = to_string(1 << i);
            sort(s.begin(), s.end());
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n)
    {
        if (st.empty())
        {
            buildset();
        }

        string s = to_string(n);
        sort(s.begin(), s.end());

        return st.count(s);
    }
};

int main()
{
    Solution sol;
    cout << sol.reorderedPowerOf2(215);
    return 0;
}