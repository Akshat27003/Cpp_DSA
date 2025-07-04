#include<iostream>
using namespace std;

/*
    for n=4, print:
    D
    C D
    B C D
    A B C D
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    char ch = 'A' + n - 1;
    for(int i = 0; i < n; i++)
    {
        for(char elt = ch - i; elt <= ch; elt++)
        {
            cout << elt << " ";
        }
        cout << endl;
    }
    return 0;
}