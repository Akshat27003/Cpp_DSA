#include<bits/stdc++.h>
using namespace std;

/*
Given an array of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. 
If there are multiple elements that appear a maximum number of times, find the smallest of them.

Please note that this section might seem a bit difficult without prior knowledge on what hashing is, 
we will soon try to add basics concepts for your ease! If you know the concepts already please go 
ahead to give a shot to the problem. Cheers!


Examples:
(1)
Input: arr = [1, 2, 2, 3, 3, 3]
Output: 3
Explanation: The number 3 appears the most (3 times). It is the most frequent element.
(2)
Input: arr = [4, 4, 5, 5, 6]
Output: 4
Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.
(3)
Input: arr = [10, 9 ,7]
Output:
7

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^4
*/


int main()
{
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Array Elements are: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxVal = -1;
    for(int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, arr[i]);
    }

    // creating hash[] arr and initialize with 0.
    int hash[maxVal+1] = {0};

    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++; // pre computation.
    }
    
    int maxCnt = 0; // max frequency
    int elt = -1; // for getting to the element having max frequency.
    for(int i = 0; i <= maxVal; i++)
    {
        // updating max freq and max freq elt.
        if(hash[i] > maxCnt)
        {
            maxCnt = hash[i];
            elt = i;
        }
    }
    cout << "The element with max frequency in the given array is: " << elt << endl;
    // TC: 3*O(N), SC: O(maxVal).
}