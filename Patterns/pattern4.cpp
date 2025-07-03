#include<iostream>
using namespace std;

/*
    for n=4, print:
    1
    2 2
    3 3 3
    4 4 4 4
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
            cout << (i + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}