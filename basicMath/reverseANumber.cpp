#include<bits/stdc++.h>
using namespace std;

// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.
// for n=25, return 52.
// for n=123, return 321.
// for n=45, return 54.
int reverseNum(int num)
{
    int revNum = 0;
    while(num != 0)
    {
        int lastDigit = num % 10;
        revNum = (revNum * 10) + lastDigit;
        num = num / 10;
    }
    return revNum;
}

// TC: O(log10(n))
// SC: O(1)

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "The reverse of the given number is: " << reverseNum(n) << endl;

    return 0;
}