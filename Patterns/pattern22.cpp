#include<iostream>
#include<algorithm> //for using min() function.
using namespace std;

/*
    for n=4, print:
    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 2 2 3 4
    4 3 2 1 2 3 4
    4 3 2 2 2 3 4
    4 3 3 3 3 3 4
    4 4 4 4 4 4 4
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < ((2 * n) - 1); i++)
    {
        for(int j = 0; j < ((2 * n) - 1); j++)
        {
            int top = i;
            int bottom = (2 * n) - 2 - i;
            int left = j;
            int right = (2 * n) - 2 - j;
            int minVal = min(min(top, bottom), min(left, right));
            cout << (n - minVal) << " ";
        }
        cout << endl;
    }
    return 0;
}