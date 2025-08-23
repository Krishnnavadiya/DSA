#include <bits/stdc++.h>
using namespace std;

// 121. Best Time to Buy and Sell Stock

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {2, 4, 1};
    cout << sol.maxProfit(prices);
    return 0;
}