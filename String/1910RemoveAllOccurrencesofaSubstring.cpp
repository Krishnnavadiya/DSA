#include <bits/stdc++.h>
using namespace std;

// 1910. Remove All Occurrences of a Substring

string removeOccurrences(string s, string part)
{
    
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string str = "ddaabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(str, part);
}