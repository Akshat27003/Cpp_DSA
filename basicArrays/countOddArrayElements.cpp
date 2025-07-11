#include<bits/stdc++.h>
using namespace std;

/*
Given an array of n elements. The task is to return the count of the number of odd numbers in the array.


Examples:
Input: n=5, array = [1,2,3,4,5]
Output: 3
Explanation: The three odd elements are (1,3,5).
(2)
Input: n=6, array = [1,2,1,1,5,1]
Output: 5
Explanation: The five odd elements are one 5 and four 1's.
(3)
Input: n=5, array = [1,3,5,7,9]
Output:
5
*/

int countOddNumbersInArray(int arr[], int size)
{
    int count = 0;
    // traversing through each element
    for(int i = 0; i < size; i++)
    {
        // checking for odd element
        if(arr[i] % 2 == 1)
        {
            count++;
        }
    }
    return count;
}
// TC: O(N), O(1).

int main()
{
    int n;
    cout << "Enter the size of the array between 1 and 100 (1, 100 included): " << endl;
    cin >> n;
    int arr[100] = {0}; 
    for(int i = 0; i < n; i++)
    {
        cout << "Enter element number: " << (i + 1) << endl; 
        cin >> arr[i];
    }
    cout << "The number of odd elements in the given array is: " << countOddNumbersInArray(arr, n) << endl;

    return 0;
}