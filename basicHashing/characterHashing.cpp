#include<bits/stdc++.h>
using namespace std;

int main()
{
    // hashing for lowercase chars only.
    // for all chars, we can take hash[] arr of size 256.
    // for uppercase or lowercase chars explicitly, we can take hash[] arr of size 26.
    int n;
    cout << "Enter size of char array:" << endl;
    cin >> n;
    vector<char> arr(n);

    int hash[26] = {0};
    cout << "Enter elements into the vector: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]-'a']++; // for uppercase, we can subtract by 'A'.
    }
    // TC: O(N)

    cout << "The char array elements are: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // TC: O(N)

    int q;
    cout << "Enter no of queries:" << endl;
    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch;
        cout << "The frequency of the given character is: " << hash[ch - 'a'] << endl;
    }
    // TC: O(q)

    return 0;
}