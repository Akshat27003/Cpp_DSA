#include<bits/stdc++.h>
using namespace std;

int main()
{
    //pow(x,y) -> returns x raised to the power y.
    // it can take double values and returns double values.
    //present in cmath which is covered by bits/stdc++.h
    int n1 = 2;
    int n2 = 9;
    cout << "2 raised to the power 9 is: " << pow(n1,n2) << endl;
    double n3 = 2.5;
    int n4 = 2;
    cout << "2.5 raised to the power 2 is: " << pow(n3,n4) << endl;

    //sqrt(n) -> returns the square root of n.
    //it returns double as well.
    int n5 = 9;
    cout << "The square root of 9 is: " << sqrt(n5) << endl;
    int n6 = 8;
    cout << "The square root of 8 is: " << sqrt(n6) << endl;
    int n7 = 6.25;
    cout << "The square root of 6.25 is: " << sqrt(n7) << endl;

    // round() -> rounds floating point num to int.
    // ceil() -> rounds off floating point num to nearest int greater than them.
    // floor() -> rounds off floating point num to nearest int smaller than them.
    // sin() -> returns the sin of an angle x, where x is in radian. sin(0) = 0. sin(pi) = 1.
    // abs() -> returns absolute value of a number. if number is negative, it returns it in positive.
    // with abs() -> positive remains positive. floating point number remains a floating point number.
    return 0;
}