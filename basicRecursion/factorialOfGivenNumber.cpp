#include<bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the factorial of n.



Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n (use 64-bits to return answer).


Examples:
(1)
Input : n = 3
Output : 6
Explanation : Factorial = 1 * 2 * 3 => 6
(2)
Input : n = 5
Output : 120
Explanation : Factorial = 1 * 2 * 3 * 4 * 5 => 120
(3)
Input : n = 4
Output:
24

Constraints:
0 <= n <= 15


*/

long long factorial(int n)
{
    if(n <= 1) // base condition: works for both n=0 and n=1.
    {
        return 1;
    }
    return n * factorial(n - 1); //recursive function call.
}
// TC: O(N), SC: O(N).

int main()
{
    int n;
    cout << "Enter number from 0 to 15 (0 and 15 included): " << endl;
    cin >> n;
    cout << "The factorial of the given number is: " << factorial(n) << endl;
    return 0;
}