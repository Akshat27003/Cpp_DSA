#include<bits/stdc++.h>
using namespace std;

/*
Given a string, the task is to reverse it. The string is represented by an array of characters s. 
Perform the reversal in place with O(1) extra memory.

Note: no need to return anything, modify the given list.

Examples:
(1)
Input : s = ["h", "e" ,"l" ,"l" ,"o"]
Output : ["o", "l", "l", "e", "h"]
Explanation : The given string is s = "hello" and after reversing it becomes s = "olleh".
(2)
Input : s = ["b", "y" ,"e" ]
Output : ["e", "y", "b"]
Explanation : The given string is s = "bye" and after reversing it becomes s = "eyb".
(3)
Input : s = ["h", "a" ,"n" ,"n" ,"a", "h"]
Output:
["h", "a" ,"n" ,"n" ,"a", "h"]

Constraints:
1 <= s.length <= 105
s consist of only lowercase and uppercase English characters.
*/

void reverseString(string& s) // pass by reference.
{
    int left = 0;
    int right = s.length()-1;
    while(left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
// Tc: O(N/2), SC: O(1).

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "The string is: " << s << endl;
    reverseString(s);
    cout << "The reverse of the given string is: " << s << endl;
    return 0;
}