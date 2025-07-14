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
1 <= n <= 10^5
1 <= arr[i] <= 10^4
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
    bool visited[maxVal + 1] = {false};

    int elt1 = -1;
    int elt2 = -1;
    int maxFreq = 0;
    int secondMaxFreq = 0;

    for(int i = 0; i < n; i++)
    {
        int cnt = 0; // for current element.
        if(visited[arr[i]] == false)
        {
            visited[arr[i]] = true;
            for(int j = 0; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            // new max frequency element case
            if(cnt > maxFreq)
            {
                secondMaxFreq = maxFreq;
                maxFreq = cnt;
                elt2 = elt1;
                elt1 = arr[i];
            }
            // if multiple maxFreq element are there
            // and we get a smaller element with maxFreq
            else if(cnt == maxFreq)
            {
                if(arr[i] < elt1)
                {
                    elt1 = arr[i];
                }
            }            
            // 2nd most freq element.. cnt > secondMaxFreq but cnt < maxFreq
            else if(cnt > secondMaxFreq)
            {
                secondMaxFreq = cnt;
                elt2 = arr[i];
            }
            // if multiple secondMaxFreq element are there
            // and we get a smaller element with secondMaxFreq
            else if(cnt == secondMaxFreq && arr[i] < elt2)
            {
                elt2 = arr[i];
            }
        }
    }
    // TC: O(N^2)
    // SC: O(maxVal).
    cout << "The element occurring 2nd most times in the Array is: " << elt2 << endl;
    return 0;
}