#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of the Vector: " << endl;
    cin >> n;

    vector<int> arr(n); // declaration.

    // input elements given by user.
    cout << "Enter elements in the vector: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
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

    // finding the max value entered in the vector by the user.
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    // TC: O(N)

    // declaring hash array of size [maxVal + 1] and initialize with 0.
    int hash[maxVal + 1] = {0};

    // storing the count of occurence of each element in the vector arr at the corresponding index in hash[] arr.
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    // Tc: O(N)
    
    // input no of queries from user.
    int q;
    cout << "Enter the number of queries: " << endl;
    cin >> q;
    while(q--)
    {
        int num;
        cin >> num;
        if(num > maxVal)
        {
            cout << "Element does not exist!" << endl;
        }
        else{
            cout << "The frequency of " << num << " in the array: " << hash[num] << endl;
        }
    }

    // This can work if the maxVal in vector arr is 10^6.
    // size of hash arr[] can't be more than 10^6 if it is inside main()
    // if it is global it can be 10^7.
    // if boolean hash arr[], size can be 10^8.
    return 0;
}