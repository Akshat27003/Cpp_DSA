#include<iostream>
using namespace std;

int main()
{
    // take integer marks as input and print the following grades as per the marks:
    // Grade A if marks >= 90
    // Grade B if marks >= 70
    // Grade C if marks >= 50
    // Grade D if marks >= 35
    // Fail, otherwise.

    int marks;
    cout << "Enter Marks: ";
    cin >> marks;
    if (marks >= 90)
    {
        cout << "Grade A" << endl;
    }
    else if (marks >= 70)
    {
        cout << "Grade B" << endl;
    }
    else if (marks >= 50)
    {
        cout << "Grade C" << endl;
    }
    else if (marks >= 35)
    {
        cout << "Grade D" << endl;
    }
    else 
    {
        cout << "Fail" << endl;
    }
    return 0;
}