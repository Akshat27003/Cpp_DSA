#include<bits/stdc++.h>
using namespace std;

// creating comparator to sort array / vector elements in descending order.
bool internalComparator(int elt1, int elt2)
{
    if(elt1 < elt2)
    {
        return false;
    }
    return true;
}

int main()
{
    //we can create our own customized comparators and we can use it as per our needs.
    //we can modify sort() algorithm as per our need.
    int arr[] = {5, 6, 1, 2};
    cout << "arr before sorting: " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(arr, arr + 4); // it will sort in ascending order using default comparator provided in stl.
    cout << "arr after sorting: " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    int arr2[] = {5, 6, 1, 2};
    cout << "arr before sorting in decreasing order using custom comparator: " << endl;
    for(auto i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(arr2, arr2 + 4, internalComparator); //sorting using custom comparator.
    cout << "arr after sorting in decreasing order using custom comparator: " << endl;
    for(auto i : arr2)
    {
        cout << i << " ";
    }

    return 0;
}