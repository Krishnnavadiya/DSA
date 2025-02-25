#include <bits/stdc++.h>
using namespace std;

//1524. Number of Sub-arrays With Odd Sum

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int MOD = 1000000007;
        int odd_count = 0;
        int even_count = 1;
        int total = 0;
        int prefix_sum = 0;

        for (int ele : arr)
        {
            prefix_sum += ele;
            if (prefix_sum & 1)
            {
                total = (total + even_count) % MOD;
                odd_count++;
            }
            else
            {
                total = (total + odd_count) % MOD;
                even_count++;
            }
        }
        return total;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = sol.numOfSubarrays(arr);
    cout << "Number of subarrays with odd sum: " << result << endl;

    return 0;
}