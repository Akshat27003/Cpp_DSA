#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). 
Return the number of prime numbers in the range.
A prime number is a number which has no divisors except, 1 and itself.

Examples:
(1)
Input: n = 6
Output: 3
Explanation: Prime numbers in the range [1, 6] are 2, 3, 5.
(2)
Input: n = 10
Output: 4
Explanation: Prime numbers in the range [1, 10] are 2, 3, 5, 7.
*/

bool checkPrime(int num)
{
    if(num == 1)
    {
        return false;
    }
    for(int i = 2; (i * i) <= num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrime(int num)
{
    int count = 0;
    for(int i = 1; i <= num; i++)
    {
        if(checkPrime(i))
        {
            count = count + 1;
        }
    }
    return count;
}
// TC: O(N*sqrt(N))
// SC: O(1)

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "The number of PRIME NUMBERS from 1 to " << n << " are: " << countPrime(n) << endl;
    return 0;
}