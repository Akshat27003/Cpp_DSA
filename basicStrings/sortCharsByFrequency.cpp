#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.

If two or more characters have same frequency then arrange them in alphabetic order.


Examples:
(1)
Input : s = "tree"
Output : ['e', 'r', 't' ]
Explanation : The occurrences of each character are as shown below :
e --> 2
r --> 1
t --> 1.
The r and t have same occurrences , so we arrange them by alphabetic order.
(2)
Input : s = "raaaajj"
Output : ['a' , 'j', 'r' ]
Explanation : The occurrences of each character are as shown below :
a --> 4
j --> 2
r --> 1
(3)
Input : s = "bbccddaaa"
Output:
['a', 'b', 'c', 'd']

Constraints:
1 <= s.length <= 105
s consist of only lowercase English characters.
*/

//implementing custom comparator.
//to sort in descending order of frequency of char
// and in case same freq of char is there, sort in ascending order or simply alphabetical order
bool comp(pair<int, char> p1, pair<int, char> p2) 
{
    if(p1.first > p2.first) // freq1 > freq2
    {
        return true;
    }
    if(p1.first < p2.first) //freq1 < freq2
    {
        return false;
    }
    if(p1.first == p2.first) // same freq
    {
        if(p1.second < p2.second) // if ascending order of chars is there
        {
            return true;
        }
        return false; // if ascending order of chars is not there.
    }
}

vector<char> charsOfStringByFreq(string s)
{
    pair<int, char> freq[26];
    for(int i = 0; i < 26; i++)
    {
        freq[i] = {0, (i + 'a')}; // initializing all pairs of freq with 0 as int val and chars from a to z.
    }
    for(int i = 0; i <s.length(); i++)
    {
        freq[s[i] - 'a'].first++; // mapping frequency with char.
    }
    sort(freq,freq+26,comp); // sorting using custom comparator

    vector<char> answer;
    for(int i = 0; i < 26; i++)
    {
        if(freq[i].first == 0) //the first occurrence of 0 freq after sorting in decreasing order
        // means all further chars have 0 frequency.
        {
            break;
        }
        answer.push_back(freq[i].second); //pushing the required chars in order to answer vector.
    }
    return answer;
}
// TC: O(N) + O(26) + O(26log26) + O(26) -> near about O(N) after ignoring constants.
// SC: O(3*26) -> near about O(1) i.e. constant.

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "The string is: " << s << endl;
    vector<char> solution = charsOfStringByFreq(s);
    for(auto i : solution)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}