#include<bits/stdc++.h>
using namespace std;

int main()
{
    //unordered_set stores unique elements only.
    //no particular order (not ascending nor descending).
    //no concept of lower_bound() and upper_bound().
    //most of the times, it has better time complexity than ordered set barring rare cases.
    //no concept of indexing in sets.
    //declaration
    unordered_set<int> ust;

    //adding elements to unordered_set.
    ust.insert(1);
    ust.insert(2);
    ust.insert(1); //this 1 won't be added to the unordered set as it is repeated.
    ust.insert(11);
    ust.insert(11); //this 11 won't be added to the unordered set as it is repeated.
    ust.insert(12);

    //printing all elements of unordered_set.
    //no particular order of storing.
    //using for each loop
    for(auto it : ust)
    {
        cout << it << " ";
    }
    cout << endl;

    //find() -> returns an iterator to the element if it finds the element in unordered set. otherwise, it returns ust.end().
    auto itr = ust.find(11);
    auto itr2 = ust.find(14);
    cout << *itr << endl;
    if(itr2 == ust.end())
    {
        cout << "Element not found!";
    }
    cout << endl;

    //using for loop with iterators.
    auto startItr = ust.begin();
    auto endItr = ust.end();
    for(auto i = startItr; i != endItr; i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    for(auto i = ust.begin(); i != ust.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}