#include<bits/stdc++.h>
using namespace std;

int main()
{

    //sort() algorithm is used to sort containers like vector, array.
    //sort() modifies the original container.
    //sort(start,end,comparator) -> if comparator not mentioned, it uses default comparator (ascending order).
    //sort(startPoint, endPoint) -> sorts all elements from start to end.
    int arr[5] = {6, 2, 1, 8, 7};
    cout << "ARRAY BEFORE USING INBUILT SORTING ALGO: " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(arr, arr + 5);

    cout << "ARRAY AFTER USING INBUILT SORTING ALGO: " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    //sorting and vectors.
    vector<int> v1 = {6, 2, 1, 8, 7};
    cout << "VECTOR BEFORE USING INBUILT SORTING ALGO: " << endl;
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(v1.begin(), v1.end()); // sorts entire vector.
    cout << "VECTOR AFTER USING INBUILT SORTING ALGO: " << endl;
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v2 = {6, 2, 1, 8, 7};
    cout << "VECTOR BEFORE USING INBUILT SORTING ALGO: " << endl;
    for(auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(v2.begin(), v2.begin() + 3); //sorts from start to the 3rd element [index 2], [index 3] excluded.
    cout << "VECTOR AFTER USING INBUILT SORTING ALGO FOR A PARTICULAR RANGE: " << endl;
    for(auto i : v2)
    {
        cout << i << " ";
    }
    return 0;
}