#include<iostream>
using namespace std;

/*
    for n=4, print:
    *
    * *
    * * *
    * * * *
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
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}