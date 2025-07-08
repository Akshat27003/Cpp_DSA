#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. Return the largest digit present in the number.
Eg.
for n=25, return 5
for n=99, return 9
*/

int largestDigitOfNum(int num)
{
    int largest = 0;
    while(num != 0)
    {
        int target = num % 10;
        if(target > largest)
        {
            largest = target;
        }
        num = num / 10;
    }
    return largest;
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "The largest digit in the given number is: " << largestDigitOfNum(n) << endl;

    return 0;
}