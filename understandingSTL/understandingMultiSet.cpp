#include<bits/stdc++.h>
using namespace std;

int main()
{
    //multiset allows us to store repeated elements as well.
    //it stores in increasing / ascending order.
    // no concept of indexing in multiset

    //declaration
    multiset<int> ms; // empty container

    //inserting values
    ms.insert(1);
    ms.insert(0);
    ms.insert(2);
    ms.insert(1);
    ms.insert(1);
    ms.insert(0);

    //printing.
    for(auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    //find() -> returns iterator to first occurrence of an element.
    //returns ms.end() if element is not in multiset.
    auto itr = ms.find(1); // on dereferencing, it wiil give 1.
    cout << *itr << endl;

    auto itr2 = ms.find(8); // this returns ms.end().
    if(itr2 == ms.end())
    {
        cout << "element not found!" << endl;
    }
    cout << endl;

    //erase()
    for(auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;    

    ms.erase(1); //deletes all occurence of the given element which is 1 here.

    for(auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    //to delete only 1 occurence of an element, use find with erase.
    for(auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    auto itr3 = ms.find(0);
    
    ms.erase(itr3);
    
    for(auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    
    //upper_bound, lower_bound is same as set.
    //count() -> returns number of occurence of an element in the multiset.
    multiset<int> ms2 = {0, 0, 0, 1, 1, 1, 1, 1, 2, 3, 4, 5, 5};
    cout << "1 occurs: " << ms2.count(1) << " times in the multiset." << endl;
    return 0;
}