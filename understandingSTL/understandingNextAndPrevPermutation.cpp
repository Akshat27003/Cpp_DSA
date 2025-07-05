#include<bits/stdc++.h>
using namespace std;
int main()
{
    // next_permutation() Algorithm
    // it modifies the original data structure or container.
    // works with arrays, vectors, strings and other containers as well.
    // generates the next lexicographical permutations for the container till no further possibility is there.
    // next_permutation(beginPoint, endPoint) 
    // if for string str, we want permutation keeping 'c' as fixed.
    // we can use next_permutation(str.begin(),str.end()-1);
    string str = "abc";

    cout << "All possible next permutations for string str: " << endl;
    do {
        cout << str << endl;
    } while(next_permutation(str.begin(), str.end()));

    cout << str << endl; //string str becomes the lowest lexicographically sorted string after all permutations.

    cout << "All possible next permutations for string str without changing 'c': " << endl;
    do {
        cout << str << endl;
    } while(next_permutation(str.begin(), str.end() - 1));

    //next_permutation doesn't print any previous permutation which might have come in lexicographical order.
    // if string is 'bca', it would print all lexicographical permutations after 'bca'.
    // those permutations will be -> 'cab', 'cba'.
    string str2 = "bca";
    while(next_permutation(str2.begin(), str2.end())) 
    {
        cout << str2 << endl;
    }
    cout << endl;

    string str3 = "acdb";
    do {
        cout << str3 << endl;
    } while(next_permutation(str3.begin(),str3.end()));

    cout << "The string str3 at the end of all next_permutation() is: " << str3 << endl; // str3 wont have the original string "acdb".
    // it will have "abcd" at the end as that is the lowest possible string in lexicographical order.

    
    //prev_permutation() algorithm.
    // it also modifies the original data structure or container.
    // works with arrays, vectors, strings and other containers as well.
    // generates the previous lexicographical permutations for the container till no further possibility is there.
    // prev_permutation(beginPoint, endPoint) 
    // if for string str4, we want permutations keeping 'c' as fixed.
    // we can use prev_permutation(str.begin(),str.end());
    string str4 = "cba";

    cout << "All possible previous permutations for string str4: " << endl;
    do {
        cout << str4 << endl;
    } while(prev_permutation(str4.begin(), str4.end()));

  
    cout << str4 << endl; //string resets to greatest lexicographically sorted string after all permutations.
  
    cout << "All possible previous permutations for string str4 without changing 'c': " << endl;
    do {
        cout << str4 << endl;
    } while(prev_permutation(str4.begin() + 1, str4.end()));

    //prev_permutation doesnt give us any permutation which comes later in lexicographical order.
    // if string is 'bca', it would print all lexicographical permutations before 'bca'.
    // these are 'bac', 'acb', 'abc'.
    string str5 = "bca";
    while(prev_permutation(str5.begin(), str5.end())) 
    {
        cout << str5 << endl;
    }
    cout << endl;

    string str6 = "acdb";
    do {
        cout << str6 << endl;
    } while(prev_permutation(str6.begin(), str6.end()));

    cout << "The string str3 at the end of all prev_permutation() is: " << str6 << endl; // str3 wont have the original string "acdb".
    // it will have "dcba" at the end as that is the largest string in lexicographical order.
    return 0;
}