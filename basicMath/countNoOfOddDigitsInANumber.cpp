#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to return the number of odd digits present in the number.
The number will have no leading zeroes, except when the number is 0 itself.
Eg.
for n = 5, return 1 as only 5 is the odd digit in the number.
for n = 25, return 1 as only 5 is the odd digit in the number.
*/

int countOddDigits(int num)
{
    int count = 0;
    while(num != 0)
    {
        int target = num % 10;
        if(target % 2 == 1)
        {
            count++;
        }
        num = num / 10;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "The no. of odd digits in the given number are: " << countOddDigits(n) << endl;

    return 0;
}