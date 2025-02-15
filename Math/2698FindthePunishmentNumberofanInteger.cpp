#include <bits/stdc++.h>
using namespace std;

//2698. Find the Punishment Number of an Integer

class Solution {
public:
    bool isPartition(int j, string i2, int i, int curSum) {
        int n = i2.length();
        if (j == n) {
            return (curSum == i);
        }
        for (int index = j; index < n; index++) {
            int val = stoi(i2.substr(j, index - j + 1));
            if (isPartition(index + 1, i2, i, curSum + val)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string i2 = to_string(i * i);
            if (isPartition(0, i2, i, 0)) {
                res += (i * i);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sol.punishmentNumber(n);
    cout << "Punishment Number: " << result << endl;

    return 0;
}