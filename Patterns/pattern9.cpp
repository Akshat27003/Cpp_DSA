#include<iostream>
using namespace std;

/*
    for n=4, print:
       *
      ***
     *****
    *******
    *******
     ***** 
      *** 
       * 
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    //upper half.
    for(int i = 0; i < n; i++)
    {
        for(int spaces = 0; spaces < (n - i - 1); spaces++)
        {
            cout << " ";
        }
        for(int stars = 0; stars < ((2 * i) + 1); stars++)
        {
            cout << "*";
        }
        cout << endl;
    }
        
    //lower half.
    for(int i = 0; i < n; i++)
    {
        for(int spaces = 0; spaces < i; spaces++)
        {
            cout << " ";
        }
        for(int stars = 0; stars < ((2 * n) - (2 * i) - 1); stars++)
        {
            cout << "*";
        }
        cout << endl;
    }
}