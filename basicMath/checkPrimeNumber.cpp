#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int num)
{
    // Edge Case of 1 (1 is not prime).
    if(num == 1)
    {
        return false;
    }
    for(int i = 2; (i * i) <= num; i++)
    {
        if(num % i == 0) // divisor found. num not prime.
        {
            return false; 
        }
    }
    return true; // if no divisor, num is prime and return true.
}
int main()
{
    int n; 
    cout << "Enter a number: " << endl;
    cin >> n;

    if(checkPrime(n))
    {
        cout << "The given number is a PRIME NUMBER." << endl;
    }
    else
    {
        cout << "The given number is not a PRIME NUMBER." << endl;
    }
    return 0;
}