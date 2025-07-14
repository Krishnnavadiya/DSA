#include <bits/stdc++.h>
using namespace std;

// 1290. Convert Binary Number in a Linked List to Integer

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        while (head != nullptr)
        {
            result = (result << 1) | head->val;
            head = head->next;
        }
        return result;
    }
};

int main()
{
    ListNode *node3 = new ListNode(1);
    ListNode *node2 = new ListNode(0, node3);
    ListNode *node1 = new ListNode(1, node2);

    Solution sol;
    int decimalValue = sol.getDecimalValue(node1);
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}
