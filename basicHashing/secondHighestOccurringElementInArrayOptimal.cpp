#include<bits/stdc++.h>
using namespace std;

/*
Given an array of n integers, find the second most frequent element in it. If there are multiple elements that appear a maximum number of times, find the smallest of them. If second most frequent element does not exist return -1.


Examples:
(1)
Input: arr = [1, 2, 2, 3, 3, 3]
Output: 2
Explanation: The number 2 appears the second most (2 times) and number 3 appears the most(3 times). 
(2)
Input: arr = [4, 4, 5, 5, 6, 7]
Output: 6
Explanation: Both 6 and 7 appear second most times, but 6 is smaller.
(3)
Input: arr = [10, 9 ,7, 7]
Output:
9

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

    int elt1 = -1;
    int elt2 = -1;
    int maxFreq = 0;
    int secondMaxFreq = 0;

    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for(int i = 0; i <= maxVal; i++)
    {
        if(hash[i]==0) // skipping iterations on elements having 0 frequency.
        {
            continue;
        }
        // element with maxFreq case.
        if(hash[i] > maxFreq)
        {
            secondMaxFreq = maxFreq;
            maxFreq = hash[i];
            elt2 = elt1;
            elt1 = i;
        }
        // element with secondMaxFreq case
        // hash[i] != maxFreq ensures that if multiple elements with max freq are there,
        // they are note added as secondMaxFreq and we simply pass the loop.
        // we can do if(has[i]==maxFreq) continue; to skip that iteration as well.
        else if(hash[i] > secondMaxFreq && hash[i] != maxFreq)
        {
            secondMaxFreq = hash[i];
            elt2 = i;
        }
    }
    // here we dont need to manage the case of taking the lower element
    // because when we traverse hash[] array, we are traversing from lower element to greater elements.
    // we dont need to update as the first element we get would suffice.
    // TC: 3*O(N), SC: O(maxVal).
    cout << "The element occurring 2nd most times in the Array is: " << elt2 << endl;
    return 0;
}