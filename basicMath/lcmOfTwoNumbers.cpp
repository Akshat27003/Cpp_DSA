#include<bits/stdc++.h>
using namespace std;

//Brute Approach:
// check the max of the 2 numbers and its multiple
// and see if it divides both numbers n1, n2.
// if it does, that is the lcm. return it.
// TC: O(N1*N2). 
// In worst case, like 9 and 10, the lcm would be the product of 2 number.
// This will happen when gcd is 1. No common divisor other than 1.
// SC: O(1).
int lcmTwoNumBrute(int num1, int num2)
{
    int maxNum = max(num1, num2);
    int i = 1;
    int multiple;
    while(true)
    {
        multiple = i * maxNum;
        if(multiple % num1 == 0 && multiple % num2 == 0)
        {
            return multiple; // will always work at some point 
            // and loop will be terminated.
            // we will get out of the function.
        }
        i++;
    }
    return -1; // safe fallback. never executed.
}

// Optimal Approach:
// using GCD {Euclidean Algo} and formula : num1*num2 = GCD * LCM
// TC: O(log(min(n1,n2))).
// SC: O(1).
int lcmTwoNumOptimal(int num1, int num2)
{
    int temp1 = num1;
    int temp2 = num2;
    while(temp1 != 0 && temp2 != 0)
    {
        if(temp1 > temp2)
        {
            temp1 = temp1 % temp2;
        }
        else
        {
            temp2 = temp2 % temp1;
        }
    }
    int gcd = 1;
    if(temp1 == 0)
    {
        gcd = temp2;
    }
    else
    {
        gcd = temp1;
    }
    int lcm = (num1 * num2) / gcd;
    return lcm;
}

int main()
{
    int n1,n2;
    cout << "Enter first number: " << endl;
    cin >> n1;
    cout << "Enter second number: " << endl;
    cin >> n2;
    cout << "The lcm of " << n1 << " and " << n2 << " is: " << lcmTwoNumBrute(n1,n2) << endl;
    cout << "The lcm of " << n1 << " and " << n2 << " is: " << lcmTwoNumOptimal(n1,n2) << endl;
    return 0;
}