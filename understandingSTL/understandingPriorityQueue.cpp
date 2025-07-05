#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Priority Queue: underlying data structure is Heap.
    // it stores the highest element at the top (max priority queue)
    // max priority queue works on the principle of max heap.

    //declaration
    priority_queue<int> pq;

    //adding elements
    pq.push(5);
    pq.push(6);
    pq.push(10);

    //pq.top() -> prints highest element.
    cout << pq.top() << endl;

    //pq.empty() -> returns true if no element in priority queue. else false.

    //printing priority queue: it will be in descending order as top element is printed always.
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    cout << endl;

    pq.push(5);
    pq.push(6);
    pq.push(10);
    
    //pq.pop() -> deletes highest element.
    pq.pop();

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // There is another type of priority queue called min priority queue.
    // it works on the principle of min heap.
    // stores smallest element at the top.
    // min priority queue uses comparator internally. 
    // greater is the comparator here which is responsible for storing smallest element at top.

    // declaring min priority queue
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(4);
    pq2.push(5);
    pq2.push(6);
    pq2.push(1);

    //printing priority queue: it will be in ascending order as smallest element is at the top.
    while(!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    
    cout << endl;

    pq2.push(4);
    pq2.push(5);
    pq2.push(6);
    pq2.push(1);
    
    //pq.pop() -> deletes highest element.
    pq2.pop();

    while(!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;


    return 0;
}