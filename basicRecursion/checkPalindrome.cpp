#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, return true if the string is palindrome, otherwise false.



A string is called palindrome if it reads the same forward and backward.


Examples:
(1)
Input : s = "hannah"
Output : true
Explanation : The string when reversed is --> "hannah", which is same as original string , so we return true.
(2)
Input : s = "aabbaaa"
Output : false
Explanation : The string when reversed is --> "aaabbaa", which is not same as original string, So we return false.
(3)
Input : s = "aabbcccdbbaa"
Output:
false

Constraints:
1 <= s.length <= 10^3
s consist of only uppercase and lowercase English characters.

*/

bool checkPalindrome(int left, int right, string s)
{
    if(left >= right) // base condition 1.
    {
        return true;
    }

    if(s[left] != s[right]) // base condition 2.
    {
        return false;
    }

    return checkPalindrome(left + 1, right - 1, s);
}

bool isPalindrome(string s)
{
    int n = s.length();
    return checkPalindrome(0, n - 1, s);
}
// TC: O(N/2), SC: O(N/2).

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "The string is: " << s << endl;
    if(isPalindrome(s))
    {
        cout << "The given string is PALINDROME." << endl;
    }
    else
    {
        cout << "The given string is NOT PALINDROME." << endl;
    }
    return 0;
}