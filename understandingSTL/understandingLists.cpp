#include<bits/stdc++.h>
using namespace std;

int main()
{
    // list are similar to vector.
    // list allow us to insert data at / from the front.
    // underlying data structure is a linked list.
    // 0 based indexing works.
    // deque is similar to list and vector as well.
    // it works on the underlying principle of linked list as well.
    // deque supports fast insertion / deletion at both beginning and end.
    // deque might be more useful than vector or list where there is frequent insertion or deletion of elements from both ends.
    // for both list and deque, most operations of vectors are valid.

    // declaring list
    list<int> ls; // empty container.
    ls.push_back(2);
    ls.push_back(4);
    for(auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl;

    //inserting from the front.
    //push_front() and emplace_front().
    ls.push_front(1);
    for(auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl;

    ls.push_front(3);
    for(auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl;

    // deletion from both front and end.
    ls.pop_back(); // deletes last element.
    for(auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl;

    ls.pop_front(); // deletes first element.
    for(auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl;

    //declaring deque
    deque<int> dq;

    //adding elements in deque.
    dq.push_back(3);
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.push_back(4);
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.push_front(2);
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.push_front(1);
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
    
    //deleting from deque.
    dq.pop_back();
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    dq.pop_front();
    for(auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}