#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s. Return true if the string is palindrome, otherwise false. A string is called palindrome if it reads the same forward and backward.


Examples:
(1)
Input : s = "hannah"
Output : true
Explanation : The given string when read backward is -> "hannah", which is same as when read forward.
Hence answer is true.
(2)
Input : s = "aabbaaa"
Output : false
Explanation : The given string when read backward is -> "aaabbaa", which is not same as when read forward.
Hence answer is false.
(3)
Input : s = "aabbccbbaa"
Output:
true

Constraints:
1 <= s.length <= 105
s consist of only uppercase and lowercase English characters.
*/

bool checkPalindrome(string& s) // pass by reference.
{
    int left = 0;
    int right = s.length()-1;
    while(left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
// Tc: O(N/2), SC: O(1).

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "The string is: " << s << endl;
    if(checkPalindrome(s))
    {
        cout << "The given string is a PALINDROME STRING." << endl;
    }
    else
    {
        cout << "The given string is NOT a PALINDROME STRING." << endl;
    }
    return 0;
}