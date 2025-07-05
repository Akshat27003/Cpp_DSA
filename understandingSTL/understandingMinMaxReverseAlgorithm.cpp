#include<bits/stdc++.h>
using namespace std;

int main()
{
    //max_element(), min_element() Algorithm always return an iterator in case of containers.
    // returns pointer in case of array.
    //max_element(startPoint,endPoint) returns the iterator / pointer to the largest element in the given range.
    //min_element(startPoint,endPoint) returns the iterator / pointer to the smallest element in the given range.
    //we can customize range to find min or max element in a particular range and not the entire container.
    int arr[] = {7, 6, 5, 10, 3};
    auto it = max_element(arr, arr + 5);
    cout << "The largest element in array arr is: " << *it << endl;

    vector<int> v1 = {7, 6, 5, 10, 3};
    auto it2 = min_element(v1.begin(), v1.end());
    cout << "The smallest element in vector v1 is: " << *it2 << endl;

    //reverse() algorithm
    //it reverses the array elements in the given range.
    //it could be the entire array or part of it depending on the range given.
    //reverse() changes or modifies the original array.
    vector<int> v2 = {7, 6, 5, 10, 3};
    cout << "The vector v2 before reversal was: " << endl;
    for(auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    reverse(v2.begin(), v2.end());
    cout << "The vector v2 after reversal is: " << endl;
    for(auto i : v2)
    {
        cout << i << " ";
    }
    return 0;
}