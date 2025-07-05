#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Stack: LIFO (Last In First Out)
    // Queue: FIFO (First In First Out)
    
    //declaring stack
    stack<int> st; // empty container.

    //adding elements into the stack.
    st.push(1); 
    st.push(3);
    st.push(2);
    st.push(4);

    //st.size() gives us the size of the stack
    //st.empty() returns boolean value true if stack is empty, false if not empty.
    //st.top() gives top most element.
    //st.pop() deletes top most element.
    //if stack is empty, and we try to access top most element, it will give run time error.

    //iterating and printing all elements of stack
    while(st.empty() == false)
    {
        cout << st.top() << " "; //print elt at the top
        st.pop(); //then delete the element at the top
        // repeat till stack becomes empty and condition becomes false.
    }
    cout << endl;

    //declaring queue
    queue<int> q; // empty container.

    //adding elements into the queue.
    q.push(1); 
    q.push(3);
    q.push(2);
    q.push(4);

    //q.size() gives us the size of the queue
    //q.empty() returns boolean value true if queue is empty, false if not empty.
    //q.front() gives first input element of the queue.
    //q.pop() deletes first input element of the queue.
    // if queue is empty, and we try to access first input most element, it will give run time error.

    //iterating and printing all elements of queue
    while(q.empty() == false)
    {
        cout << q.front() << " "; //print first element of the queue
        q.pop(); //then delete first element of the queue
        // repeat till queue becomes empty and condition becomes false.
    }
    cout << endl;

    return 0;
}