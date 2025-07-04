#include<iostream>
using namespace std;

/*
    for n=4, print:
    *      *
    **    **
    ***  ***
    ********
    ***  ***
    **    **
    *      *
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    //upper half
    for(int i = 0; i < n; i++)
    {
        //stars
        for(int j = 0;j <= i; j++)
        {
            cout << "*";
        }
        
        //spaces
        for(int spaces = 0; spaces < (2 * (n - i -1)); spaces++)
        {
            cout << " ";
        }

        //stars
        for(int j = 0;j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }


    //lower half
    for(int i = 0; i < (n - 1); i++)
    {
        //stars
        for(int j = 0; j < (n - i - 1); j++)
        {
            cout << "*";
        }

        //spaces
        for(int spaces = 0; spaces <= ((2 * i) + 1); spaces++)
        {
            cout<< " ";
        }

        //stars
        for(int j = 0; j < (n - i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }    
    return 0;
}