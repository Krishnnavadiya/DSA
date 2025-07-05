#include <bits/stdc++.h>
using namespace std;

// 1011. Capacity To Ship Packages Within D Days

class Solution
{
public:
    bool isFeasible(int maxCapacity, vector<int> &weights, int allowedDays)
    {
        int daysRequired = 1;
        int currentLoad = 0;

        for (int weight : weights)
        {
            if (weight > maxCapacity)
            {
                return false;
            }

            currentLoad += weight;

            if (currentLoad > maxCapacity)
            {
                daysRequired++;
                currentLoad = weight;
            }
        }

        return daysRequired <= allowedDays;
    }

    int shipWithinDays(vector<int> &weights, int totalDays)
    {
        int minCapacity = 0;
        int maxCapacity = 0;

        for (int weight : weights)
        {
            minCapacity = max(minCapacity, weight);
            maxCapacity += weight;
        }

        int optimalCapacity = 0;

        while (minCapacity <= maxCapacity)
        {
            int midCapacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if (isFeasible(midCapacity, weights, totalDays))
            {
                optimalCapacity = midCapacity;
                maxCapacity = midCapacity - 1;
            }
            else
            {
                minCapacity = midCapacity + 1;
            }
        }

        return optimalCapacity;
    }
};

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    Solution sol;
    cout << sol.shipWithinDays(weights, days);
}