#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. Return the value of n! or n factorial.
Factorial of a number is the product of all positive integers less than or equal to that number.

Examples:
(1)
Input: n = 2
Output: 2
Explanation: 2! = 1 * 2 = 2.
(2)
Input: n = 5
Output: 120
Explanation: 5! = 1 * 2 * 3 * 4 * 5 = 120.
(3)
Input: n = 0
Output: 1
Explanation: 0! is defined as 1 always.
*/

int factorial(int num)
{
    int answer = 1;
    for(int i = 1; i <= num; i++)
    {
        answer = answer * i;
    }
    return answer;
}
// TC: O(n)
// SC: O(1)
// for bigger values of n, n becomes huge very quickly
// In that case, use long long or long
// for even bigger values, we might need to create array 
// to store values at indexes of array.
int main()
{
    int n;
    cout << "Enter a number between 0 and 12 (0 and 12 included): " << endl;
    cin >> n;

    cout << "The factorial of the given number is: " << factorial(n) << endl;
}