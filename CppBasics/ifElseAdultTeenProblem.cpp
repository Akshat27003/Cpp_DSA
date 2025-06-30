#include<iostream>
using namespace std;

int main()
{
    // take age as input. print "Adult" if age >= 18 and "Teen" if age < 18.

    int age;
    cout << "Enter Age: ";
    cin >> age;
    if (age >= 18)
    {
        cout << "Adult" << endl;
    }
    else
    {
        cout << "Teen" << endl;
    }
    return 0;
}