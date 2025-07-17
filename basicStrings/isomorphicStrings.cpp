#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic. 
Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.


Examples:
(1)
Input : s = "egg" , t = "add"
Output : true
Explanation : The 'e' in string s can be replaced with 'a' of string t.
The 'g' in string s can be replaced with 'd' of t.
Hence all characters in s can be replaced to get t.
(2)
Input : s = "apple" , t = "bbnbm"
Output : false
Explanation : It can be proved that no solution exists for this example.
All the "b"s in t have to take places of "a", "p", "l", which requires "p" to be mapped to "b", but that makes it impossible for "p" at index 2 (0-indexed) to become "n". Thus no solution exists.
(3)
Input : s = "paper" , t = "title"
Output:
true

Constraints:
1 <= s.length <= 103
s.length == t.length
s and t consist of only lowercase English letters.

*/

bool isIsomorphic(string s, string t)
{
    // 2 arrays for mapping char of one string in the other.
    int smap[256] = {0}; // for mapping chars of string s with t.
    int tmap[256] = {0}; // for mapping chars of string t with s.
    for(int i = 0; i < s.length(); i++) // take any length as it is given both strings are equal in length.
    {
        if(smap[s[i]] != 0) // if char s[i] is already visited and mapped
        {
            if(smap[s[i]] != (t[i] + 1)) // checking if current mapping for chars of string s with t is consistent with previous mapping.
            {
                return false;
            }
        }

        if(tmap[t[i]] != 0) // if char t[i] is already visited and mapped
        {
            if(tmap[t[i]] != (s[i] + 1)) // checking if current mapping for chars of string t with s is consistent with previous mapping.
            {
                return false;
            }
        }    
        smap[s[i]] = t[i] + 1; // mapping char of string s with chars of string t.
        tmap[t[i]] = s[i] + 1; // mapping char of string t with chars of string s.
        // smap[s[i]] = t[i] + 1 and not smap[s[i]] = t[i].
        // this is to avoid conflict between ASCII value 0 and default 0 values of array.
    }
    return true; // if all mapping is correct, strings are isomorphic.
}
// TC: O(N) -> N is length of either strings.
// SC: O(2*256) = constant.

int main()
{
    string s;
    cout << "Enter string 1: " << endl;
    cin >> s;
    string t;
    cout << "Enter string 2 of same size as string 1: " << endl;
    cin >> t;
    
    if(isIsomorphic(s, t))
    {
        cout << "The 2 strings are ISOMORPHIC." << endl;
    }
    else
    {
         cout << "The 2 strings are NOT ISOMORPHIC." << endl;
    }
    return 0;
}