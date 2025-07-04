#include<iostream>
using namespace std;

/*
    for n=4, print:
    A
    A B
    A B C
    A B C D
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        // char based loop
        for(char ch = 'A'; ch <= ('A' + i); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}