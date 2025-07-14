#include<bits/stdc++.h>
using namespace std;

/*
Given an array of n integers, find the sum of the frequencies of the highest occurring number and lowest occurring number.

Examples:
(1)
Input: arr = [1, 2, 2, 3, 3, 3]
Output: 4
Explanation: The highest frequency is 3 (element 3), and the lowest frequency is 1 (element 1). Their sum is 3 + 1 = 4.
(2)
Input: arr = [4, 4, 5, 5, 6]
Output: 3
Explanation: The highest frequency is 2 (elements 4 and 5), and the lowest frequency is 1 (element 6). Their sum is 2 + 1 = 3.
(3)
Input: arr = [10, 9, 7, 7, 8, 8, 8]
Output:
4

Constraints:
1 <= n <= 105
1 <= arr[i] <= 104
*/

int main()
{
    int n;
    cout << "Enter no of elements in Array:" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the Array:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Array is:" << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    
    int maxVal = -1;
    for(int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, arr[i]);
    } 

    int hash[maxVal + 1] = {0};
    int maxFreq = 0; // for storing max frequency
    int minFreq = n; // for storing min frequency
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for(int i = 0; i <= maxVal; i++)
    {
        if(hash[i] != 0)
        {
            maxFreq = max(maxFreq, hash[i]); //taking max to get max frequency through the hash[] arr.
            minFreq = min(minFreq, hash[i]); //taking min to get min frequency through the hash[] arr.
        }
    }

    int answer = maxFreq + minFreq; // taking sum of max and min freq.
    cout << "The sum of the frequencies of the highest occurring number and lowest occurring number: " << answer << endl;
    // TC: 3*O(N), SC: O(maxVal).
    return 0;
}