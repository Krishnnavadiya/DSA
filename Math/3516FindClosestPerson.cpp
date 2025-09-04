#include <bits/stdc++.h>
using namespace std;

// 3516. Find Closest Person

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int person1, person2;
        if (z > x)
            person1 = z - x;
        else
            person1 = x - z;

        if (z > y)
            person2 = z - y;
        else
            person2 = y - z;

        if (person1 == person2)
            return 0;
        return person1 < person2 ? 1 : 2;
    }
};

int main()
{
    Solution sol;
    cout << sol.findClosest(2, 3, 5);
    return 0;
}