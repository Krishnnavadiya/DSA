#include <bits/stdc++.h>
using namespace std;

// 1394. Find Lucky Integer in an Array

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        /* Brute Force
        int result = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for (auto& p : mp) {
            cout << p.first << " " << p.second << endl;
            if (p.first == p.second) {
                result = max(p.first, result);
            }
        }
        return result;
        */

        int freq[501] = {0};

        for (int num : arr)
        {
            freq[num]++;
        }

        for (int i = 500; i >= 1; --i)
        {
            if (freq[i] == i)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 2, 2, 3, 3};
    cout << sol.findLucky(arr);
}
