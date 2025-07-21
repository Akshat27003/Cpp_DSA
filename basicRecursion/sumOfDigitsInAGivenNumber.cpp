#include<bits/stdc++.h>
using namespace std;

/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.


Examples:
(1)
Input : num = 529
Output : 7
Explanation : In first iteration the digits sum will be = 5 + 2 + 9 => 16
In second iteration the digits sum will be 1 + 6 => 7.
Now single digit is remaining , so we return it.
(2)
Input : num = 101
Output : 2
Explanation : In first iteration the digits sum will be = 1 + 0 + 1 => 2
Now single digit is remaining , so we return it.
(3)
Input : num = 38
Output:
2

Constraints:
0 <= num <= 2^31 - 1


*/

int summ(int num)
{
    if(num == 0) // all digits done traversing for summation.
    {
        return 0;
    }
    return (num % 10) + summ(num / 10); // add current digit and pass remaining digits
}

int addDigits(int num)
{
    if(num < 10) //  makes sure we return num (essentially sum now) when it is single digit or simply said less than 10.
    {
        return num;
    }
    // recursion within recursion. dual / multiple recursion.
    return addDigits(summ(num)); // keep adding digits by calling sum function on returned values.
    // till we get single digit number as sum.
}
// TC: O(log10(N)) * const -> very less as no matter how big the num is after adding it is bound to become smaller.
// essentially, TC: O(log10(N))
// SC: O(log10(N)).

int addDigits2(int num)
{
    while(num > 9) // loop to keep doing it till num is single digit.
    {
        int sum = 0;
        while(num != 0) // loop to calculate sum of digits.
        {
            sum += (num % 10);
            num /= 10;
        }
        num = sum; // reinitializing num to be operated again till it becomes single digit value.
    }
    return num;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Repeatedly adding the digits of the number and the result we get till we get a single digit sum (recursively): " << addDigits(n) << endl;
    cout << "Repeatedly adding the digits of the number and the result we get till we get a single digit sum (iteratively): " << addDigits2(n) << endl;
    return 0;
}