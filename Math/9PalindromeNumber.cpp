#include <bits/stdc++.h>
using namespace std;

//9. Palindrome Number

class Solution
{
public:
    bool isPalindrome(int x)
    {
        long long num = 0, original = x;

        if (x < 0)
            return false;
        while (x != 0)
        {
            int reminder = x % 10;
            num = num * 10 + reminder;
            x = x / 10;
        }
        return num == original;
    }
};

int main(){
    Solution sol;
    int x;
    
    cout << "Enter a number: ";
    cin >> x;

    cout<<sol.isPalindrome(x);
}