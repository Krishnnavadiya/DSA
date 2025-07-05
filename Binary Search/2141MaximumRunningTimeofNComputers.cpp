#include <bits/stdc++.h>
using namespace std;

// 2141. Maximum Running Time of N Computers

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &bat)
    {
        long long total_time = 0;
        for (auto x : bat)
            total_time += x;

        sort(bat.rbegin(), bat.rend());

        for (int i = 0; i < bat.size(); i++, n--)
        {
            if (bat[i] <= (total_time / n))
                break;

            total_time -= bat[i];
        }

        return total_time / n;
    }
};

int main()
{
    vector<int> batteries = {2, 2, 3};
    int n = 2;
    Solution sol;
    cout << sol.maxRunTime(n, batteries);
}