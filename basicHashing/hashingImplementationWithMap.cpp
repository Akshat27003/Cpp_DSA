#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of the Vector: " << endl;
    cin >> n;

    vector<int> arr(n); // declaration.

    // declaring unordered_map for hashing key with values for the vector arr.
    unordered_map<int, int> hash; // can be normal, sorted map as well.

    // input elements given by user and store the count of occurence of each element in the vector arr at the corresponding index in map.
    cout << "Enter elements in the vector: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++; 
    }
    // TC: O(N)

    // printing
    cout << "The Vector is: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // TC: O(N)

    // input no of queries from user.
    int q;
    cout << "Enter the number of queries: " << endl;
    cin >> q;
    while(q--)
    {
        int num;
        cin >> num;
        cout << "The frequency of " << num << " in the array: " << hash[num] << endl;
        // if num doesnt occur even once, when we do hash[num], a key 'num' is created and its value is 0.
    }
    // TC: O(q)

    // This can work if the maxVal in vector arr is 10^6.
    // size of hash arr[] can't be more than 10^6 if it is inside main()
    // if it is global it can be 10^7.
    // if boolean hash arr[], size can be 10^8.
    return 0;
}