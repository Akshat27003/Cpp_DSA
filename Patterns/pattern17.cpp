#include<iostream>
using namespace std;

/*
    for n=4, print:
       A
      ABA
     ABCBA
    ABCDCBA
*/

int main()
{
    int n;
    cout << "Enter value of n: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        // for spaces:
        for(int spaces = 0; spaces < (n - i -1); spaces++)
        {
            cout<<" ";
        }

        //for chars:
        char ch = 'A';
        for(int j = 0; j < ((2 * i) + 1); j++)
        {
            cout << ch;
            if(j < i)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        cout << endl;
    }
    return 0;
}