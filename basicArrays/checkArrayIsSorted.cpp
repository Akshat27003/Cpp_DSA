#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr of size n, the task is to check if the given array is sorted in 
(ascending / Increasing / Non-decreasing) order. If the array is sorted then return True, else return False.

Examples:
(1)
Input: n = 5, arr = [1,2,3,4,5]
Output: True
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, 
So the answer is True.
(2)
Input: n = 5, arr = [5,4,6,7,8]
Output: False
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, 
So the answer is False. Here element 5 is not smaller than or equal to its future elements.
(3)
Input: n = 5, arr = [5,4,3,2,1]
Output:
False
*/

int checkArraySortBrute(int arr[], int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        for(int j = (i + 1); j < size; j++)
        {
            if(arr[j] < arr[i])
            {
                return false;
            }
        }
    }
    return true;
}
// TC: O(N^2), O(1).

int checkArraySortOptimal(int arr[], int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
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
    cout << "The Array Elements in order are: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(checkArraySortBrute(arr,n))
    {
        cout << "Given Array is sorted." << endl;
    }
    else
    {
        cout << "Given Array is not sorted." << endl;
    }

    if(checkArraySortOptimal(arr,n))
    {
        cout << "Given Array is sorted." << endl;
    }
    else
    {
        cout << "Given Array is not sorted." << endl;
    }

    return 0;
}