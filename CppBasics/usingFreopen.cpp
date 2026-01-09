#include<iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin); // if you ever try to read input, read it from input.txt file.
    freopen("output.txt","w",stdout); // whatever i print using cout, send it to output.txt file.

    int a, b;
    cin >> a >> b; // read the value of a and b from input.txt
    // suppose 5 3 is written in input.txt. a = 5 and b = 3.
    // input.txt should be in the SAME DIRECTORY from where the program in being run.
    cout << a + b; // Output: 5 + 3 = 8 will be stored and reflected in output.txt file
    
    return 0;
}