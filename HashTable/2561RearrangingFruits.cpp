#include<bits/stdc++.h>
using namespace std;

// 2561. Rearranging Fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> total_counts;
        for (int fruit : basket1) total_counts[fruit]++;
        for (int fruit : basket2) total_counts[fruit]++;

        long long min_val = LLONG_MAX;
        for (auto const& [fruit, count] : total_counts) {
            if (count % 2 != 0) return -1;
            min_val = min(min_val, (long long)fruit);
        }
        
        vector<long long> fruits_to_swap;
        map<int, int> count1;
        for (int fruit : basket1) count1[fruit]++;
        
        for (auto const& [fruit, total_count] : total_counts) {
            int diff = count1[fruit] - (total_count / 2);
            for (int i = 0; i < abs(diff); ++i) {
                fruits_to_swap.push_back(fruit);
            }
        }
        
        sort(fruits_to_swap.begin(), fruits_to_swap.end());
        
        long long total_cost = 0;
        int swaps_to_make = fruits_to_swap.size() / 2;
        for (int i = 0; i < swaps_to_make; ++i) {
            total_cost += min(fruits_to_swap[i], 2 * min_val);
        }
        
        return total_cost;
    }
};

int main() {
    Solution sol;

    vector<int> basket1 = {4, 2, 2, 2};
    vector<int> basket2 = {1, 4, 1, 2};

    long long result = sol.minCost(basket1, basket2);
    if (result == -1) {
        cout << "Not possible to make baskets identical." << endl;
    } else {
        cout << "Minimum cost to make baskets identical: " << result << endl;
    }

    return 0;
}