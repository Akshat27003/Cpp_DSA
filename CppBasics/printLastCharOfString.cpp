#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Given a string s. Return the last character of the given string s.

    string s;
    cout << "Enter a string: ";
    cin >> s;
    char ans = s[s.size()-1];
    cout << "The last character of the string is: " << ans << endl;
    return 0;
}