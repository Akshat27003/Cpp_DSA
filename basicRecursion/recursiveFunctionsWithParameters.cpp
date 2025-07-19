#include<bits/stdc++.h>
using namespace std;

// Tasks:
// (1) Print 1 to N using Tail Recursion.
// (2) Print 1 to N using Head Recursion.
// (3) Print N to 1 using Tail Recursion.
// (4) Print N to 1 using Head Recursion.

void tailRecursion1toN(int i, int N)
{
    if(i > N) //base condition
    {
        return;
    }
    cout << i << " "; // code block
    tailRecursion1toN(i + 1, N); // function call at the end.
}

void headRecursion1toN(int n)
{
    if( n == 0) // base condition
    {
        return;
    }
    headRecursion1toN(n - 1); // function call before code block
    cout << n << " "; // code block
}

void tailRecursionNto1(int n)
{
    if(n == 0) // base condition
    {
        return;
    }
    cout << n << " "; // code block
    tailRecursionNto1(n - 1); // function call at the end.
}

void headRecursionNto1(int i, int N)
{
    if(i > N) // base condition.
    {
        return;
    }
    headRecursionNto1(i + 1, N); // function call before code block
    cout << i << " "; // code block
}

int main()
{
    int n;
    cout << "Enter number: " << endl;
    cin >> n;
    cout << "The number is: " << n << endl;
    cout << endl;
    tailRecursion1toN(1,n);
    cout << endl;
    headRecursion1toN(n);
    cout << endl;
    tailRecursionNto1(n);
    cout << endl;
    headRecursionNto1(1,n);
    return 0;
}