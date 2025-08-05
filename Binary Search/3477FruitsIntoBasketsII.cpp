#include <bits/stdc++.h>
using namespace std;

// 3477. Fruits Into Baskets II

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        const int n = fruits.size();
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (fruits[i] <= baskets[j])
                {
                    ans--;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> fruits = {2, 3, 1};
    vector<int> baskets = {1, 2, 2};

    int result = sol.numOfUnplacedFruits(fruits, baskets);
    cout << "Number of unplaced fruits: " << result << endl;
    return 0;
}
