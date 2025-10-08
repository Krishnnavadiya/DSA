#include <bits/stdc++.h>
using namespace std;

// 2300. Successful Pairs of Spells and Potions

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int idx = bs(potions, spells[i], success);
            if (idx != -1)
                ans[i] = potions.size() - idx;
        }
        return ans;
    }

private:
    int bs(vector<int> &potions, long long strength, long long success)
    {
        int low = 0, high = potions.size() - 1, idx = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (1LL * potions[mid] * strength >= success)
            {
                idx = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return idx;
    }
};

int main()
{
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    Solution sol;
    vector<int> result = sol.successfulPairs(spells, potions, success);

    cout << "Successful pairs for each spell: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
