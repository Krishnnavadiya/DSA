#include <bits/stdc++.h>
using namespace std;

// 3440. Reschedule Meetings for Maximum Free Time II

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime,
                    vector<int> &endTime)
    {
        vector<int> gap(1, startTime[0]);
        for (int i = 1; i < startTime.size(); ++i)
            gap.push_back(startTime[i] - endTime[i - 1]);
        gap.push_back(eventTime - endTime.back());

        vector<int> largestRight(gap.size(), 0);
        for (int i = gap.size() - 2; i >= 0; --i)
            largestRight[i] = max(largestRight[i + 1], gap[i + 1]);

        int ans = 0, largestLeft = 0;
        for (int i = 1; i < gap.size(); ++i)
        {
            int curGap = endTime[i - 1] - startTime[i - 1];
            if (curGap <= max(largestLeft, largestRight[i]))
                ans = max(ans, gap[i - 1] + gap[i] + curGap);
            ans = max(ans, gap[i - 1] + gap[i]);
            largestLeft = max(largestLeft, gap[i - 1]);
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // First line: two integers eventTime and n (number of meetings)
    // Second line: n integers for startTime[]
    // Third line: n integers for endTime[]
    int eventTime, n;
    cin >> eventTime >> n;

    vector<int> startTime(n), endTime(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> startTime[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> endTime[i];
    }

    Solution sol;
    int result = sol.maxFreeTime(eventTime, startTime, endTime);
    cout << result << "\n";

    return 0;
}