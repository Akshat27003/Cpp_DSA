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

    bool visited[maxVal+1] = {false};

    int maxFreq = -1;
    int minFreq = n;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0; // current elt frequency.
        if(visited[arr[i]]==false)
        {
            visited[arr[i]]=true;
            for(int j = 0; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    cnt++; // updating freq.
                }
            }
            maxFreq = max(maxFreq,cnt); //update max frequency on finding more frequency.
            minFreq = min(minFreq, cnt); //update min frequency on finding lower frequency.
        }
    }
    int answer = maxFreq + minFreq;
    cout << "The sum of the frequencies of the highest occurring number and lowest occurring number: " << answer << endl;
    // TC: O(N^2), SC: O(maxVal).
    return 0;
}