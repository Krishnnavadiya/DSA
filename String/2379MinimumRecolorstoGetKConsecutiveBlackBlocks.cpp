#include <bits/stdc++.h>
using namespace std;

// 2379. Minimum Recolors to Get K Consecutive Black Blocks

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int mini = INT_MAX;
        for (int i = 0; i < blocks.size() - k + 1; i++)
        {
            int cnt = 0;
            for (int j = i; j < i + k; j++)
            {
                if (blocks[j] == 'W')
                {
                    cnt++;
                }
            }
            mini = min(mini, cnt);
        }
        return mini;
    }
};

int main()
{
    Solution sol;
    string blocks;
    int k;

    cout << "Enter the block sequence (only 'B' and 'W'): ";
    cin >> blocks;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.minimumRecolors(blocks, k);

    cout << "Minimum recolors needed: " << result << endl;

    return 0;
}
