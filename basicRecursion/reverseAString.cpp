#include<bits/stdc++.h>
using namespace std;

/*
Given an input string as an array of characters, write a function that reverses the string.


Examples:
(1)
Input : s = ["h", "e", "l", "l", "o"]
Output : ["o", "l", "l", "e", "h"]
Explanation : The given string is s = "hello" and after reversing it becomes s = "olleh".
(2)
Input : s = ["b", "y", "e" ]
Output : ["e", "y", "b"]
Explanation : The given string is s = "bye" and after reversing it becomes s = "eyb".
(3)
Input : s = ["h", "a", "n", "n", "a", "h"]
Output:
["h", "a", "n", "n", "a", "h"]

Constraints:
1 <= s.length <= 10^3
s consist of only lowercase and uppercase English characters.

*/

void reverseStr(int left, int right, vector<char>& s)
{
    if(left >= right)
    {
        return;
    }
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverseStr(left + 1, right - 1, s);
}

vector<char> reverseString(vector<char>& s)
{
    int n = s.size();
    reverseStr(0, n - 1, s);
    return s;
}
// TC: O(N/2), SC: O(N/2).


int main()
{
    int n;
    cout << "Enter size of vector of char: " << endl;
    cin >> n;
    vector<char> s(n);
    cout << "Enter chars in the vector: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    } 
    cout << "The elements of the vector before reversing are: " << endl;
    for(auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    s = reverseString(s);
    cout << "The elements of the vector after reversing are: " << endl;
    for(auto i : s)
    {
        cout << i << " ";
    }    
    return 0;
}