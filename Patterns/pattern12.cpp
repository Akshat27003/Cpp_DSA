#include<iostream>
using namespace std;

/*
    for n=4, print:
    1      1
    12    21
    123  321
    12344321
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        // increasing numbers
        for(int j = 0; j <= i; j++)
        {
            cout << (j + 1);
        }

        // spaces
        for(int spaces = 0; spaces < (2 * (n - i - 1)); spaces++)
        {
            cout << " ";
        }

        // decreasing numbers
        int start = i + 1;
        for(int j = 0; j <= i; j++)
        {
            cout << start;
            start--;
        }
        cout << endl;
    }
    return 0;
}