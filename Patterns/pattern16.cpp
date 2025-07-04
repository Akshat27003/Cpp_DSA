#include<iostream>
using namespace std;

/*
    for n=4, print:
    A
    B B
    C C C
    D D D D
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    char ch = 'A';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }
    return 0;
}