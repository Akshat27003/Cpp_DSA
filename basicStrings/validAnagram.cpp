#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.


Examples:
(1)
Input : s = "anagram" , t = "nagaram"
Output : true
Explanation : We can rearrange the characters of string s to get string t as frequency of all characters from both strings is same.
(2)
Input : s = "dog" , t = "cat"
Output : false
Explanation : We cannot rearrange the characters of string s to get string t as frequency of all characters from both strings is not same.
(3)
Input : s = "eat" , t = "tea"
Output:
true

Constraints:
1 <= s.length , t.length <= 5*104
s and t consist of only lowercase English letters

*/

//brute approach
bool anagramCheck(string s, string t)
{
    sort(s.begin(), s.end()); // sort string s. inbuilt sort algo takes O(NlogN) Time Complexity
    sort(t.begin(), t.end()); // sort string t.
    // if s and t are equal (they become the same string), then they are anagram.
    return(s == t);
}
// TC: O(NlogN) + O(MlogM) -> N is size of string s, M is size of string M.
// SC: O(1).

// optimized approach
bool anagramCheck2(string s, string t)
{
    if(s.length() != t.length()) // is the strings are of different sizes.
    {
        return false; // they are not anagram of each other.
    }
    int freq[26] = {0}; //initializing frequency array of size 26 as it covers all lowercase english alphabet.
    for(int i = 0; i < s.length(); i++)
    {
        freq[s[i]-'a']++; 
    }

    for(int i = 0; i < t.length(); i++)
    {
        freq[t[i]-'a']--; 
    }

    // if the result of above 2 for loops makes the frequency array as completely 0 at all indexes, 
    // it is a valid anagram. Otherwise, it is not.
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
// TC: O(N) + O(26)
// SC: O(26).

int main()
{
    string s;
    cout << "Enter string 1: " << endl;
    cin >> s;
    string t;
    cout << "Enter string 2 of same size as string 1: " << endl;
    cin >> t;
    
    if(anagramCheck(s, t))
    {
        cout << "The 2 strings are ANAGRAM of each other." << endl;
    }
    else
    {
         cout << "The 2 strings are NOT ANAGRAM." << endl;
    }

    if(anagramCheck2(s, t))
    {
        cout << "The 2 strings are ANAGRAM of each other." << endl;
    }
    else
    {
         cout << "The 2 strings are NOT ANAGRAM." << endl;
    }
    return 0;
}