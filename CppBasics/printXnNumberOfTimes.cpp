#include<iostream>
using namespace std;

int main()
{
    // Given two integers X and N, print the value X on the screen N times. Move to the next line after printing.

    int X, N;
    cout << "Enter the number to be printed: ";
    cin >> X;
    cout << "Enter the number of times the above number to be printed: "; 
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cout << X << " ";
    }
    cout << endl;
    return 0;
}