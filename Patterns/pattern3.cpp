#include<iostream>
using namespace std;

/*
    for n=4, print:
    1
    1 2
    1 2 3
    1 2 3 4
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << (j + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}