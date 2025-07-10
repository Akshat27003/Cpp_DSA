#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to check whether it is an armstrong number or not. 
Return true if it is an armstrong number, otherwise return false.
An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

Examples:
(1)
Input: n = 153
Output: true
Explanation: Number of digits : 3.
1 + 125 + 27 = 153.
Therefore, it is an Armstrong number.

(2)
Input: n = 12
Output: false
Explanation: Number of digits : 2.
1 + 4 = 5.
Therefore, it is not an Armstrong number.
*/

bool checkArmstrong(int num)
{
    int duplicateNum = num;
    int digits = log10(num) + 1;
    int sum = 0;
    while( duplicateNum != 0)
    {
        int lastDigit = duplicateNum % 10;
        sum = sum + round(pow(lastDigit, digits));
        duplicateNum = duplicateNum / 10;
    }
    return (num == sum); // true if number is armstrong. else, false.
}
// TC: O(digits*log2(digits)). O(digits) is for the loop, O(log2(digits)) for pow() function.
// digits = log10(N) -> N is the number of digits.
// TC: O(log10(N)*log2(log10(N))).
// SC: O(1)

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    if(checkArmstrong(n))
    {
        cout << "The given number is an ARMSTRONG NUMBER. " << endl;
    }
    else
    {
        cout << "The given number is NOT an ARMSTRONG NUMBER. " << endl;
    }
    return 0;
}