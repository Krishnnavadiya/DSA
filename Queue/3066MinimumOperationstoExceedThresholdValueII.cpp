#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    int count = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

    while (pq.size() > 1 && pq.top() < k)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long newElement = 2LL * first + second;
        pq.push(newElement);
        count++;
    }
    return count;
}

int main()
{
    vector<int> vc = {2, 11, 10, 1, 3};
    int number = 10;
    cout << minOperations(vc, number);
}