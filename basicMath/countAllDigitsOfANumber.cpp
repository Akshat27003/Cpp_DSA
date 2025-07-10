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

// first way: using division.
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

//second way: directly using log10 function
// log10 function is present in cmath header.
// takes double val and returns double val.
int countDigits2(int num)
{
    int cnt = 0;
    if(num == 0)
    {
        return 1;
    }
    else{
        cnt = log10(num) + 1; //log10(num) is typecasted to int.
    }
    return cnt;
}

// TC: O(log10(n)).
// SC: O(1)

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "The entered number contains: " << countDigits(n) << " digits. " << endl;
    cout << "The entered number contains: " << countDigits2(n) << " digits. " << endl;

    return 0;
}