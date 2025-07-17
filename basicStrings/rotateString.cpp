#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.


Examples:
(1)
Input : s = "abcde" , goal = "cdeab"
Output : true
Explanation : After performing 2 shifts we can achieve the goal string from string s.
After first shift the string s is => bcdea
After second shift the string s is => cdeab.
(2)
Input : s = "abcde" , goal = "adeac"
Output : false
Explanation : Any number of shift operations cannot convert string s to string goal.
(3)
Input : s = "abcde" , goal = "abcde"
Output:
true

Constraints:
1 <= s.length <= 100
1 <= goal.length <= 100
s and goal consist of only lowercase English letters.
*/

//brute force:
bool rotateStr(string s, string goal)
{
    int n = s.length();
    if(s.length() != goal.length()) // if s and goal are of different size.
    {
        return false;
    }
    string left = ""; // empty string initially.
    for(int i = 0; i < (n - 1); i++)
    {
        string right = s.substr(i); // take the entire string starting from index i.
        if(right + left == goal) // if it is possible to get goal string from string s.
        {
            return true;
        }
        left += s[i]; // left string is to be added to the right string.
        // add char at index i of string s to left string which will be added at the end of right string
        // after each shift/rotation.
    }
    return false; // if after completely rotating the string or completely iterating,
    // we dont get goal, return false.
}
// TC: O(N^2), SC: O(N).

//optimized approach:
bool rotateStr2(string s, string goal)
{
    if(s.length() != goal.length())
    {
        return false;
    }
    s = s + s; // concatenating the string, TC: O(N).
    // extra space: O(N)
    return (s.find(goal)) != string::npos; //npos is returned if goal is not found in s.
    //npos represents a constant representing the largest possible value for size_t type.
    // s.find(goal) -> user RABIN KARP String Matching Algorithm internally.
}
// s.find(goal) -> best and avg case TC: O(N) for searching a substr in a string.
// TC: O(N) + O(2*N)
// SC: O(N)

int main()
{
    string s;
    cout << "Enter string 1: " << endl;
    cin >> s;
    string goal;
    cout << "Enter string 2: " << endl;
    cin >> goal;
    
    if(rotateStr(s, goal)) // calling brute force approach
    {
        cout << "string 1 can be rotated to get string 2." << endl;
    }
    else
    {
         cout << "string 1 can not be rotated to get string 2." << endl;
    }    
    
    if(rotateStr2(s, goal)) // calling optimized approach
    {
        cout << "string 1 can be rotated to get string 2." << endl;
    }
    else
    {
         cout << "string 1 can not be rotated to get string 2." << endl;
    }    
    return 0;
}
