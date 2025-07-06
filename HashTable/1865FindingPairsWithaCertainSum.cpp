#include <bits/stdc++.h>
using namespace std;

// 1865. Finding Pairs With a Certain Sum

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : this->nums1) {
            freq1[num]++;
        }
        for (int num : this->nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (auto& [num, cnt] : freq1) {
            res += cnt * freq2[tot - num];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4, 5};

    FindSumPairs *obj = new FindSumPairs(nums1, nums2);
    cout << "Count of pairs with sum 6: " << obj->count(6) << endl;
    obj->add(1, 1);

    cout << "Count of pairs with sum 6 after add: " << obj->count(6) << endl;
    obj->add(2, 2);

    cout << "Count of pairs with sum 8 after add: " << obj->count(8) << endl;
    delete obj;

    return 0;
}