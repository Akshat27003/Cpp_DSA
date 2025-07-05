#include<bits/stdc++.h>
using namespace std;

int main()
{

    //declaring a pair
    pair<int,int> p1 = {2, 8}; // both values need not be int. they can be anything.

    //accessing pairs
    cout << p1.first << endl; // prints first value
    cout << p1.second << endl; // prints second value

    //another way of declaring and initializing pair
    pair<int, char> p2 = make_pair(3, 'b');
    cout << "Before modifying: " << endl;
    cout << p2.first << ", " << p2.second;
    cout << endl;

    //modifying values of a pair.
    p2.first = 5;
    p2.second= 'f';
    cout << "After modifying: " << endl;
    cout << p2.first << ", " << p2.second;
    cout << endl;

    //user input in pair.
    pair<int, string> p3; //pair without initializing value.
    //p3.first contains 0.
    //p3.second contains "" i.e. empty string.
    cout << "Enter num:";
    cin >> p3.first;
    cout << "Enter string:";
    cin >> p3.second;

    cout << "The number entered was: " << p3.first << " and the string entered was: " << p3.second << endl;

    // pair within a pair is possible as well.
    pair<pair<int, int>,pair<int, int>> p4 = {{1,2},{3,4}};
    // accessing elements of pair within a pair.
    cout << p4.first.first << ", " << p4.first.second << endl;
    cout << p4.second.first << ", " << p4.second.second << endl;

    return 0;
}
