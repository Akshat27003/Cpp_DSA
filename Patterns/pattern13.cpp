#include<iostream>
using namespace std;

/*
    for n=4, print:
    1
    2 3
    4 5 6
    7 8 9 10
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    int num = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    return 0;
}