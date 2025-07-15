#include<string>
#include<iostream>
using namespace std;

int main()
{
    // declaring and initializing string.
    string str = "akshat";
    cout << "The string is: " << str << endl;

    // string are mutable in c++. we can modify strings.
    str = str + 'j'; // appends j to the string (concatenate).
    // this takes lot of Time Complexity.
    cout << "The string is: " << str << endl;

    str += 'j'; // takes lesser time.
    cout << "The string is: " << str << endl;

    //length/size of the string
    cout << "The length of the string is: " << str.length() << endl;
    cout << "The size of the string is: " << str.size() << endl;

    //Traversing through elements of string and printing.
    for(int i = 0; i < str.length(); i++)
    {
        cout << "Element at index " << i << " : " << str[i] << endl;
        // each index of a string represents a char.
        // char ch = str[i] would work perfectly.
    }
    
    // substring.
    // str.substr(startIndex,no_of_elements) -> print the specified no of elements from startIndex given.
    cout << str.substr(2,3) << endl; // print "sha"
    // str.substr(startIndex) -> prints till the end starting from startIndex
    cout << str.substr(2) << endl; // prints "shatjj"
    // str.substr() -> prints entire string itself. 
    cout << str.substr() << endl;   

    // appending 2 string. (concatenating 2 strings) using + operator
    string str2 = "rajat";
    str += " " + str2;
    cout << str << endl;

    int val = 'c'; // char typecasted to int
    // ascii value of char 'c' stored in val.
    cout << val << endl;
    // if in a given array, we access element using a char as index, 
    // essentially the index corresponding to the char's ASCII value is taken. 
    return 0;
}