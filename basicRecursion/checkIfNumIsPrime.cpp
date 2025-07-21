#include<bits/stdc++.h>
using namespace std;

/*
Given an integer num, return true if it is prime otherwise false.

A prime number is a number that is divisible only by 1 and itself.


Examples:
(1)
Input : num = 5
Output : true
Explanation : The factors of 5 are 1 and 5 only.
So it satisfies the prime number condition.
(2)
Input : num = 15
Output : false
Explanation : The factors of 15 are 1, 3, 5, 15 only.
As the number has factors other than 1 and itself, So it is not a prime number.
(3)
Input : num = 41
Output:
true

Constraints:
1 <= num <= 10^4


*/

bool isPrime(int i, int num)
{
    if((i * i) > num) //base condition 1
    {
        return true;
    }
    if(num % i == 0) //base condition 2
    {
        return false;
    }
    return isPrime(i + 1, num);

}

bool checkPrime(int num)
{
    if(num == 1)
    {
        return false;
    }
    return isPrime(2, num);
}
// TC: O(sqrt(N)), SC: O(sqrt(N))

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    if(checkPrime(n))
    {
        cout << "The given number is PRIME." << endl;
    }
    else
    {
        cout << "The given number is NOT PRIME." << endl;
    }
    return 0;
}