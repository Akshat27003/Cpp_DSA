#include<iostream>
using namespace std;

/*
    for n=4, print:
    *
    * *
    * * *
    * * * *
    * * *
    * *
    * 
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    //upper half
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    //lower half.
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = 0; j < (n - i - 1); j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}