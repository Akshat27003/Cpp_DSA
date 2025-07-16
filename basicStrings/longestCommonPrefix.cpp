#include<bits/stdc++.h>
using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Examples:
(1)
Input : str = ["flowers" , "flow" , "fly", "flight" ]
Output : "fl"
Explanation : All strings given in array contains common prefix "fl".
(2)
Input : str = ["dog" , "cat" , "animal", "monkey" ]
Output : ""
Explanation : There is no common prefix among the given strings in array.
(3)
Input : str = ["lady" , "lazy"]
Output:
"la"

Constraints:
1 <= str.length <= 200
1 <= str[i].length <= 200
str[i] contains only lowercase English letters.
*/

string lcp(vector<string>& str) // pass by reference.
{
    sort(str.begin(), str.end()); // sorts in dictionary arrangement
    // whatever is common in first and last string will be common in all strings.
    // TC: O(NlogN)
    int n = str.size();
    string first = str[0]; // taking first string of array
    string last = str[n - 1]; // taking last string of array
    string smallerStr = min(first, last); // taking smaller string from first and last string for iterating on it.
    // using inbuilt min function.
    string answer = ""; // empty string.
    for(int i = 0; i < smallerStr.length(); i++)
    {
        if(first[i] != last[i]) // if the chars of first and last string dont match break out of loop.
        {
            break;
        }
        answer += first[i]; // if the chars match, add it to answer.
    }
    return answer;
}
int main()
{
    int n; 
    cout << "Enter the number of strings to enter: " << endl;
    cin >> n;
    vector<string> str(n); // declaring a vector of strings of size n.
    for(int i = 0; i < n; i++)
    {
        cout << "Enter string at index " << i << ": ";
        cin >> str[i];
    }

    cout << "The string is: " << endl;
    for(auto i : str)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The LONGEST COMMON PREFIX among all strings in the given Vector of strings is: " << lcp(str) << endl;
    return 0;
}