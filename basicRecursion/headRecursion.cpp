#include<bits/stdc++.h>
using namespace std;

// Recursion: Function calls itself.
// In head recursion, the recursive call occurs before any other processing in the function. 
//The function waits for the recursive call to return before proceeding with any operation.
// Basically backtracking is there..
// Base condition is used to make sure that Infinite functional calls dont place.
// Infinite function calls or a code in which base condition never executes results in SEGMENTATION FAULT / STACK OVERFLOW.
// System maintains function memory stack with all values and the order of functional calls.


// using global variable.
int i = 1;

// for printing name.
void printName(int n)
{
    if(i > n) // base condition.
    {
        return;
    }
    i++;
    printName(n); // recursive function call.
    cout << "Akshat!" << endl; // code block after recursive call.
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