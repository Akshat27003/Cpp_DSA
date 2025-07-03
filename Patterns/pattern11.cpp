#include<iostream>
using namespace std;

/*
    for n=4, print:
    1
    0 1
    1 0 1
    0 1 0 1
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int start = 1;
        if(i % 2 == 1) // for odd row.
        {
            start = 0;
        }
        for(int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start; // flipping the value of start at each iteration.
        }
        cout << endl;
    }
}