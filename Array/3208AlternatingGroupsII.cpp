#include <bits/stdc++.h>
using namespace std;

// 3208. Alternating Groups II

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int count = 0;
        int l = 0;
        int limit = n + k - 1;

        while (l < n)
        {
            int r = l + 1;
            while (r < limit and colors[(r - 1) % n] != colors[r % n])
                r++;
            if (r - l >= k)
                count += (r - l) - k + 1;
            l = r;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    int n, k;

    cout << "Enter the number of elements in colors array: ";
    cin >> n;

    vector<int> colors(n);

    cout << "Enter the colors (integers): ";
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.numberOfAlternatingGroups(colors, k);

    cout << "Number of alternating groups: " << result << endl;

    return 0;
}
