#include<bits/stdc++.h>
using namespace std;

int main()
{
    // set stores unique elements in ascending order.
    // no concept of indexing in sets.

    //declaring set.
    set<int> st;
    
    //adding elements to a set
    st.insert(2);
    st.insert(6);
    st.insert(4);
    st.insert(8);
    st.insert(4); // this won't be added to the set st as it is repeated.

    //printing elements of a set:
    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;

    //functions in set
    //find() -> returns iterator to the element if it is present in container.
    //if not present, it returns st.end().
    auto it = st.find(6);
    auto it2 = st.find(12); // this will return st.end().
    if(it != st.end())
    {
        cout << *it << endl; // this will print 6 as 6 is presentin set st.
    }
    if(it2 == st.end())
    {
        cout << "Element Not Found!!" << endl;
    }

    //count() -> returns 1 (no of times element occurs), if element is present in set. else, returns 0.
    cout << "1 is present: " << st.count(1) << endl;
    cout << "2 is present: " << st.count(2) << endl;

    //erase() -> deletes particular element from set.
    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;
    
    st.erase(2);
    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;
    
    //erase() with end(),begin() can be used to delete element at particular positions.
    auto itr = st.end();
    itr--; 
    st.erase(itr); //deletes 2nd last element.
    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;    

    //erase() with iterator range.
    st.insert(8);
    st.insert(10);

    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;    

    auto itr1 = st.begin();
    auto itr2 = st.end();
    itr2--; 
    itr1++;
    st.erase(itr1, itr2); //will print from 2nd element to 2nd last element, 2nd last element included.
    //the element to which itr2 is at will not be included in this range. itr2 is iterator to 10.
    for(auto i : st)
    {
        cout << i << " ";
    }
    cout << endl;  
    
    //lower_bound: returns an iterator to the element >= the given element.
    //upper_bound: returns an iterator to the next element > the given element.
    set<int> st2 = {2, 12, 21, 211, 213};
    auto itr3 = st2.lower_bound(11);
    cout << *itr3 << endl; //prints 12 as 12 >= 11.
    auto itr4 = st2.upper_bound(11); //prints 12 as 12 > 11.
    cout << *itr4 << endl;
    
    //difference between lower_bound() and upper_bound().
    auto itr5 = st2.lower_bound(12);
    cout << *itr5 << endl; //prints 12 as 12>=12 is true.
    auto itr6 = st2.upper_bound(12);
    cout << *itr6 << endl; //prints 21 as 12>12 is false. so next number > 12 is printed which is 21.

    //if there is nothing >= number given for lower bound, it returns st2.end().
    //if there is nothing > number given for upper bound, it returns st2.end().
    auto itr7 = st2.lower_bound(213); // prints 213 as 213>=213 is true.
    cout << *itr7 << endl;
    auto itr8 = st2.upper_bound(213);
    //no val > 213 in set st2 is there. itr8 returns st2.end()
    if(itr8 == st2.end())
    {
        cout << "Not bounded!" << endl; 
    }
    
    auto itr9 = st2.lower_bound(214);
    //itr9 would return st2.end() as no val >= 214 exists in st2.
    if(itr9 == st2.end())
    {
        cout << "Not bounded!" << endl;
    }
    return 0;
}