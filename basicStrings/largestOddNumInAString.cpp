#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) 
that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string may have leading zero.

Examples:
(1)
Input : s = "5347"
Output : "5347"
Explanation : The odd numbers formed by given strings are --> 5, 3, 53, 347, 5347.
So the largest among all the possible odd numbers for given string is 5347.
(2)
Input : s = "0214638"
Output : "21463"
Explanation : The different odd numbers that can be formed by the given string are --> 1, 3, 21, 63, 463, 1463, 21463.
We cannot include 021463 as the number contains leading zero.
So largest odd number in given string is 21463.
(3)
Input : s = "0032579"
Output:
"32579"

Constraints:
1 <= s.length <= 103
'0' <= s[i] <= '9'
*/


string largestOddNumInString(string s) // pass by value.
{
    // To find first odd digit index from the end of string.
    int j = -1;
    int n = s.length();
    for(int i = (n - 1); i >= 0; i--) // reverse traversal string
    {
        if((s[i] - '0') % 2 == 1) // odd digit check using ASCII Values
        {
            j = i;
            break;
        }
    }

    // To find first non zero digit index from the start of string.
    int i = 0;
    while(i < n)
    {
        if(s[i] != '0')
        {
            break;
        }
        i++;
    }

    // return the substring from ith index to jth index for largest odd int without zeros.
    return s.substr(i, (j - i + 1)); // s.substr(startIndex,no_of_chars).
}
// Tc: O(N) 
// SC: Auxiliary Space: O(1), space for Output: O(N) 

int main()
{
    string s;
    cout << "Enter a string consisting of integer digits: " << endl;
    cin >> s;
    cout << "The string is: " << s << endl;
    string result = largestOddNumInString(s);
    cout << "The largest possible odd integer from the given substring is: " << result << endl;
    return 0;
}