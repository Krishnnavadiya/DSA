#include <bits/stdc++.h>
using namespace std;

// 165. Compare Version Numbers

class Solution
{
public:
    vector<int> splitVersion(const string &version)
    {
        vector<int> parts;
        stringstream ss(version);
        string token;

        while (getline(ss, token, '.'))
        {
            parts.push_back(stoi(token));
        }
        return parts;
    }
    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; i++)
        {
            int a = (i < v1.size() ? v1[i] : 0);
            int b = (i < v2.size() ? v2[i] : 0);

            if (a < b)
                return -1;
            if (a > b)
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.compareVersion("1.2", "1.10") << endl;    // Output: -1
    cout << sol.compareVersion("1.01", "1.001") << endl;  // Output: 0
    cout << sol.compareVersion("1.0", "1.0.0.0") << endl; // Output: 0
    cout << sol.compareVersion("1.3.5", "1.3.2") << endl; // Output: 1
    return 0;
}