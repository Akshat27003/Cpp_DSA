#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.
Eg: 
for n=4, return 1
for n=0; return 1
for n=14, return 14
*/

int countDigits(int n)
{
    int count = 0;
    if( n == 0)
    {
        count = 1;
    }
    else
    {
        while(n != 0)
        {
            count++;
            n = n / 10;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "The entered number contains: " << countDigits(n) << " digits. " << endl;
    return 0;
}