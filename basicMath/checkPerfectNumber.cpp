#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to check if the number is a perfect number or not. 
Return true if it is a perfect number, otherwise, return false.
A perfect number is a number whose proper divisors (excluding the number itself) add up to the number itself.

Examples:
(1)
Input: n = 6
Output: true
Explanation: Proper divisors of 6 are 1, 2, 3.
1 + 2 + 3 = 6.
(2)
Input: n = 4
Output: false
Explanation: Proper divisors of 4 are 1, 2.
1 + 2 = 3.
(3)
Input: n = 28
Output:
true
Explanation: Proper divisors of 28 are 1, 2, 4, 7, 14.
1 + 2 + 4 + 7 + 14 = 28 
*/

// Brute Approach:
// TC: O(N)
// SC: O(1)
bool checkPerfectNumberBrute(int num)
{
    int sum = 0;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
        {
            sum = sum + i;
        }
    }
    return (num == sum);
}

// Optimal Approach: Using concept of counterpart divisor.
// if d divides n, n/d divides n as well (till sqrt(n)) after which divisors start repeating.
// TC: O(sqrt(N))
// SC: O(1)
bool checkPerfectNumberOptimal(int num)
{
    // Edge case of num=1.
    if(num == 1)
    {
        return false;
    }

    int sum = 1;
    for(int i = 2; (i * i) <= num; i++) //sqrt(num) function takes time. i*i <= num does the same job as sqrt(num).
    {
        if(num % i == 0)
        {
            sum = sum + i;
            if(i != (num / i))
            {
                sum = sum + (num / i);
            }
        }
    }
    return (num == sum);
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    if(checkPerfectNumberBrute(n))
    {
        cout << "The given number is a PERFECT NUMBER." << endl;
    }
    else
    {
        cout << "The given number is NOT a PERFECT NUMBER." << endl;
    }

    if(checkPerfectNumberOptimal(n))
    {
        cout << "The given number is a PERFECT NUMBER." << endl;
    }
    else
    {
        cout << "The given number is NOT a PERFECT NUMBER." << endl;
    }    
    return 0;
}