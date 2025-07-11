#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr of size n, the task is to find the sum of all the elements in the array.


Examples:
(1)
Input: n=5, arr = [1,2,3,4,5]
Output: 15
Explanation: Sum of all the elements is 1+2+3+4+5 = 15
(2)
Input: n=6, arr = [1,2,1,1,5,1]
Output: 11
Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11
*/

int sumArrayElts(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
// TC: O(N), O(1).

int main()
{
    int n;
    cout << "Enter the size of the array between 1 and 100 (1, 100 included): " << endl;
    cin >> n;
    int arr[100] = {0}; // all indexes of array initialized with 0.
    // without above statement, all index will have garbage values.
    for(int i = 0; i < n; i++)
    {
        cout << "Enter element number: " << (i + 1) << endl; 
        cin >> arr[i];
    }
    cout << "The sum of the elements of the given array is: " << sumArrayElts(arr, n) << endl;
    // Arrays are passed by reference to a function.

    cout << "The size of the Array is (total memory allocated): " << sizeof(arr) << endl;
    // sizeof(arr) gives the memory occupied by all the 100 elements here.
    // regardless of whether they are initialized or not.
    cout << "The size of each element of the array is: "  << sizeof(arr[0]) << endl;
    // sizeof(arr[0]) gives size of element at each index (here, it gives size of element at index: 0).
    // fill(arr(start iterator), arr + size(end iterator), 5(val)) -> algorithm 
    // it initializes each value with 5 instead of garbage value or 0.
    return 0;
}