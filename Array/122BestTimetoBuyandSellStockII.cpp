#include <bits/stdc++.h>
using namespace std;

// 122. Best Time to Buy and Sell Stock II

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        int profit = 0, i = 0, j = 1;
        while (j < n)
        {
            if (prices[j] < prices[j - 1])
            {
                i = j;
            }
            else if (j == n - 1 || prices[j] > prices[j + 1])
            {
                profit += prices[j] - prices[i];
                i = j;
            }
            j++;
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}