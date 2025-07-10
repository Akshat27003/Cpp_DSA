#include<bits/stdc++.h>
using namespace std;

// You are given an integer n. You need to check whether the number is a palindrome number or not. 
// Return true if it's a palindrome number, otherwise return false.
// A palindrome number is a number which reads the same both left to right and right to left.

/* Eg1: 
Input: n = 121
Output: true
Explanation: When read from left to right : 121.
When read from right to left : 121.
*/

/* Eg2.
Input: n = 123
Output: false
Explanation: When read from left to right : 123.
When read from right to left : 321.
*/


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

bool checkPalindrome(int num)
{
    int rev = reverseNum(num);
    return (num == rev); //returns true/false based on the operator.
    // no neeed to write if else statement.
}

// TC: O(log10(n))
// SC: O(1)

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "The reverse of the given number is: " << reverseNum(n) << endl;
    if(checkPalindrome(n)) //executes only if function returns true.
    {
        cout << "The given number is a PALINDROME NUMBER." << endl;
    }
    else //executes if function returns false.
    {
         cout << "The given number is not a PALINDROME NUMBER." << endl;
       
    }

    return 0;
}