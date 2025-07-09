#include <bits/stdc++.h>
using namespace std;

// 3439. Reschedule Meetings for Maximum Free Time I

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n + 1);

        for (int i = 1; i < n; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1]; 

        int i = 0, j = k;
        int maxa = 0, sum = 0;

        for (int w = i; w <= n && w <= j; w++) {
            sum += gap[w];
        }
        maxa = max(maxa, sum);

        while (j < n) {
            sum -= gap[i++];
            sum += gap[++j];
            maxa = max(maxa, sum);
        }

        return maxa;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int eventTime, k, n;
    cin >> eventTime >> k >> n;

    vector<int> startTime(n), endTime(n);
    for (int i = 0; i < n; i++) {
        cin >> startTime[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> endTime[i];
    }

    Solution sol;
    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << result << "\n";

    return 0;
}