#include <bits/stdc++.h>
using namespace std;

// 2099. Find Subsequence of Length K With the Largest Sum

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<pair<int, int>> topK;
        while (!pq.empty())
        {
            topK.push_back(pq.top());
            pq.pop();
        }

        sort(topK.begin(), topK.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        vector<int> result;
        for (auto &p : topK)
        {
            result.push_back(p.first);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, -2, 3, 4};
    int k = 3;
    vector<int> result = sol.maxSubsequence(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
