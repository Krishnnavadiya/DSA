#include <bits/stdc++.h>
using namespace std;

// 2410. Maximum Matching of Players With Trainers

class Solution
{
public:
    int matchPlayersAndTrainers(std::vector<int> &players,
                                std::vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int count = 0;
        int i = 0, j = 0;

        while (i < players.size() && j < trainers.size())
        {
            if (players[i] <= trainers[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};

    Solution sol;
    int result = sol.matchPlayersAndTrainers(players, trainers);

    cout << "Maximum matches: " << result << endl;

    return 0;
}
