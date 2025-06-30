#include<iostream>
using namespace std;

int main()
{
    //Given an integer array, return the sum of the 1st and last element of the array.

    int arr[20] = {0}; // all values 0.
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    int sum = arr[0] + arr[n-1];

    cout << "Sum of first and last element of first array is: " << sum << endl;

    return 0;
}