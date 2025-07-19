#include <bits/stdc++.h>
using namespace std;

// 1233. Remove Sub-Folders from the Filesystem

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (const auto &f : folder)
        {
            if (res.empty())
            {
                res.push_back(f);
            }
            else
            {
                const string &prev = res.back();
                if (f.find(prev) == 0 && f.size() > prev.size() && f[prev.size()] == '/')
                {
                    continue;
                }
                else
                {
                    res.push_back(f);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

    vector<string> result = sol.removeSubfolders(folder);

    cout << "After removing subfolders:\n";
    for (const string &f : result)
    {
        cout << f << endl;
    }

    return 0;
}