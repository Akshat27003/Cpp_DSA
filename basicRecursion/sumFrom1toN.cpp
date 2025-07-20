#include<bits/stdc++.h>
using namespace std;

/*
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.


Examples:
(1)
Input : N = 4
Output : 10
Explanation : first four natural numbers are 1, 2, 3, 4.
Sum is 1 + 2 + 3 + 4 => 10.
(2)
Input : N = 2
Output : 3
Explanation : first two natural numbers are 1, 2.
Sum is 1 + 2 => 3.
(3)
Input : N = 10
Output:
55

Constraints:
1 <= N <= 10^3
*/

int summ(int i, int n)
{
    if(i > n)
    {
        return 0;
    }
    return (i + summ((i + 1), n)); // head recursion as we are adding i after recursive function call returns.
}
// TC: O(N), SC: O(N)

int summ2(int n)
{
    if(n == 0) // base condition.
    {
        return 0;
    }
    return (n + summ2(n - 1)); // // head recursion as we are adding n after recursive function call returns.
}
// TC: O(N), SC: O(N)

/*
Most optimal way is by using formular n*(n+1)/2.
here tc will be O(1) and sc will be O(1) as well.
*/

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "The sum of integers from 1 to n is: " << summ(1,n) << endl;
    cout << "The sum of integers from 1 to n is: " << summ2(n) << endl;
    return 0;
}