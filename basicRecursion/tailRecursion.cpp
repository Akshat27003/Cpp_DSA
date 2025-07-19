#include<bits/stdc++.h>
using namespace std;

// Recursion: Function calls itself.
// Tail Recursion: the recursive call is the last operation in the function. 
// Once the function calls itself, there is no need to retain the current function's state, allowing the compiler to optimize tail recursion.
// Basically no backtracking.
// Base condition is used to make sure that Infinite functional calls dont place.
// Infinite function calls or a code in which base condition never executes results in SEGMENTATION FAULT / STACK OVERFLOW.
// System maintains function memory stack with all values and the order of functional calls.

//using global variable.
int i = 1;

// for printing name.
void printName(int n)
{
    if(i > n) // base condition.
    {
        return; // void returns nothing.
    }
    cout << "Akshat!" << endl; // code block before recursive call
    i++;
    printName(n); // recursive function call.
}
//TC for above code: O(N), SC: O(N) -> for memory call stack.

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Printing name " << n << " times:" << endl;
    printName(n);
    return 0;
}