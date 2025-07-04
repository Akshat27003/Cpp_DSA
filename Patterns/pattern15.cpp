#include<iostream>
using namespace std;

/*
    for n=4, print:
    A B C D
    A B C
    A B
    A
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        //char based loop
        for(char ch = 'A'; ch <= ('A' + (n - i - 1)); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}