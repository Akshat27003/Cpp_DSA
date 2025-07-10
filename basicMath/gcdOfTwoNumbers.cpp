#include<bits/stdc++.h>
using namespace std;

/*
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. 
Return the GCD of the two numbers.
The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.


Examples:
(1)
Input: n1 = 4, n2 = 6
Output: 2
Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6
Greatest Common divisor = 2.
(2)
Input: n1 = 9, n2 = 8
Output: 1
Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.
Greatest Common divisor = 1.
*/

//Brute approach
// TC: O(min(n1,n2))
// SC: O(1)
int gcdTwoNumBrute(int num1, int num2)
{
    int gcd = 1;
    for(int i = 2; i <= (min(num1, num2)); i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

//Better approach
// We dont need to maintain a variable and keep updating it throughout on each divisor.
// we can do a backward traversal from min to 1 and the first divisor will be the GCD.
// TC: O(min(n1,n2)). But on average it is better than previous approach.
// SC: O(1)
int gcdTwoNumBetter(int num1, int num2)
{
    for(int i = min(num1, num2); i >= 1; i--)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            return i;
        }
    }
}

//Optimal approach: Using Euclidean Algorithm.
//  Euclidean Algorithm says that:
// gcd(n1,n2) = gcd(n1-n2,n2) provided that n1>n2.
// Intuition: difference of n1,n2 is always divisible by gcd.
// |n1 - n2| % gcd == 0.
// We can reduce either reduce the larger number by smaller number.
// till one of them becomes 0. the other number will be gcd.
// to avoid  repetitive subtraction, we can divide bigger num by smaller num.
// this will directly make the bigger number smaller than the other number
// and it would directly make the bigger number the number we would have got
// had we done repetitive subtraction (smaller than the other number).
// TC: O(log(min(n1,n2)))
// SC: O(1).
int gcdTwoNumOptimal(int num1, int num2)
{
    while(num1 != 0 && num2 != 0)
    {
        if(num1 > num2)
        {
            num1 = num1 % num2;
        }
        else // handles num1 == num2 as well.
        {
            num2 = num2 % num1;
        }
    }
    if(num1 == 0)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}
int main()
{
    int n1,n2;
    cout << "Enter first number: " << endl;
    cin >> n1;
    cout << "Enter second number: " << endl;
    cin >> n2;
    cout << "The GCD of " << n1 << " and " << n2 << " is:  " << gcdTwoNumBrute(n1,n2) << endl;
    cout << "The GCD of " << n1 << " and " << n2 << " is:  " << gcdTwoNumBetter(n1,n2) << endl;
    cout << "The GCD of " << n1 << " and " << n2 << " is:  " << gcdTwoNumOptimal(n1,n2) << endl;
    return 0;
}