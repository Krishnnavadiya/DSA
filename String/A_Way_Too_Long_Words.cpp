#include <bits/stdc++.h>
using namespace std;

//Code forces: 71A. Way Too Long Words

int main()
{
    int n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i].length() > 10)
            cout << str[i].at(0) << str[i].length() - 2 << str[i].at(str[i].length() - 1) << endl;
        else
            cout << str[i] << endl;
    }
}