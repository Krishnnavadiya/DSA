#include <bits/stdc++.h>
using namespace std;

// 898. Bitwise ORs of Subarrays

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> res, cur, next;
        for (int num : arr)
        {
            next.clear();
            next.insert(num);
            for (int x : cur)
            {
                next.insert(x | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 4};

    int result = sol.subarrayBitwiseORs(arr);
    cout << "Number of unique bitwise ORs of subarrays: " << result << endl;

    return 0;
}