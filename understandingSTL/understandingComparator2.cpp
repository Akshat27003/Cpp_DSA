#include<bits/stdc++.h>
using namespace std;

/*
Problem statement:
Create a custom comparator for vector of pairs which:
firstly, sorts according to decreasing order of 2nd element of pair.
if second element is same, sorts in the ascending order of first element.
Eg:
pair<int, int> arr[] = {{1,6}, {1,5}, {2,6}, {2,9}, {3,9}} will be sorted in this order:
{{2,9}, {3,9}, {1,6}, {2,6}, {1,5}}
*/

bool internalComparator(pair<int, int> elt1, pair<int, int> elt2)
{
    if(elt1.second > elt2.second)
    {
        return true;
    }
    if(elt1.second < elt2.second)
    {
        return false;
    }
    if(elt1.second == elt2.second)
    {
        if(elt1.first > elt2.first)
        {
            return false;
        }
        return true;
    }
}

int main()
{
    pair<int, int> arr[] = {{1,6}, {1,5}, {2,6}, {2,9}, {3,9}};
    cout << "The array before sorting is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i].first << ", " << arr[i].second << endl;
    }
    // internal sorting here works like this:
    // sort in ascending order of 1st element.
    // if same, sort in increasing of 2nd element.
    sort(arr, arr + 5);
    cout << "The array after sorting is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i].first << ", " << arr[i].second << endl;
    }

    //sort using internalComaparator (custom comparator)
    pair<int, int> arr2[] = {{1,6}, {1,5}, {2,6}, {2,9}, {3,9}};
    cout << "The array before sorting using internal comparator is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr2[i].first << ", " << arr2[i].second << endl;
    }
    sort(arr2, arr2 + 5, internalComparator);
    cout << "The array after sorting using internal comparator is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr2[i].first << ", " << arr2[i].second << endl;
    }    
    return 0;
}