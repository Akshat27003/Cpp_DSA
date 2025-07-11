#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.

Examples:
(1)
Input: n=5, arr = [1,2,3,4,5]
Output: [5,4,3,2,1]
Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]
(2)
Input: n=6, arr = [1,2,1,1,5,1]
Output: [1,5,1,1,2,1]
Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].
(3)
Input: n=3, arr = [1,2,1]
Output:
[1,2,1]
*/


// Brute Approach: using temp[] array.
// in first traversal, store the value of original array in temp[] array in reverse order 
//while second traversal, overrid the value of temp[] array in original arr[] array.
// given in the problem statement that we have to modify the original array.
// TC: O(N*2), SC: O(N).
void reverseArrayBrute(int arr[], int size)
{
    int temp[size];
    for(int i = 0; i < size; i++)
    {
        temp[i] = arr[size-i-1];
    }
    for(int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}

// Better Approach: 2 pointers
// take 2 variables for taking index of array from the left and right.
// swap values at arr[left] and arr[right] using swap function or manual swapping.
// after swapping, left should move to the next index to the left
// right should move to the index to the right and swap again.
// do this till left and right become equal or cross over.
// TC: O(N/2), SC: O(1)
void reverseArrayBetter(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


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

    //Printing
    cout<< "The Array before reversal is: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArrayBrute(arr, n);

    cout<< "The Array after reversal using Brute Force approach is: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArrayBrute(arr, n);
        
    cout<< "The Array after reversing twice gives us the original array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArrayBetter(arr, n);
        
    cout<< "The same Array after reversal using the Better Approach is: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}