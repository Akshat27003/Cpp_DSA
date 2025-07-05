#include<bits/stdc++.h>
using namespace std;

int main()
{
    //vectors are dynamic array i.e. underlying principle / data structure is dynamic array.
    //They can have variable length (length dependent on input size)
    
    //declaration
    vector<int> arr; // this is an empty container right here.
    
    // adding elements in the vector at the end.
    arr.push_back(1); // method 1
    arr.push_back(2);
    arr.push_back(3);
    arr.emplace_back(4); // method 2
    arr.emplace_back(5);
    arr.emplace_back(6);
    
    //arr.size(); gives us the length or size of the vector.
    int length = arr.size();
    cout << "The length of the given array is: " << length << endl;
    
    // first way of printing all elements of vector arr.
    // using simple for loop
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // second way of printing all elements of vector arr.
    // using iterators. 
    // iterators are objects behaving sort of like pointers to elements within a container.
    // declaring iterators.
    vector<int>::iterator startIndex = arr.begin(); // arr.begin() is an iterator to the first element.
    cout << *startIndex << endl; // dereferencing values from interators.
    vector<int>::iterator endIndex = arr.end(); // arr.end() is an iterator to 1 after the last element.
    for(vector<int>::iterator i = startIndex; i != endIndex; i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // third way of printing vectors using auto.
    // we can use 'auto itr' in place of writing 'vector<int>::iterator itr' everywhere.
    // auto keyword automatically takes the value it is being equated with.
    auto startIndex2 = arr.begin();
    auto endIndex2 = arr.end();
    for(auto i = startIndex2; i != endIndex2; i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    //4th way of printing vectors.
    // using for each loop
    for(auto i : arr)
    {
        cout << i << " "; // simplest way.
    }
    cout << endl;

    // reverse iterator
    // printing array in reverse order.
    auto revStart = arr.rbegin(); // reverse iterator to last element.
    auto revEnd = arr.rend(); // reverse iterator to 1 before the first element.
    // i++ will work in reverse order only. iterates to previous available iterator.
    // i-- not applicable.
    for(auto i = revStart; i != revEnd; i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    //more ways of declaring and initializing vectors.
    // way 1
    vector<int>  arr2(5); //arr2 has size 5 at creation.
    //all values of arr2 are 0.
    for(auto i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;

    // if we do push_back, emplace_back, element will be added at next index.
    arr2.push_back(1);
    arr2.emplace_back(2);
    for(auto i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;

    //way 2
    vector<int> arr3(5,8); // vector arr3 has size 5, all elements are initialized with 8.
    for(auto i : arr3)
    {
        cout << i << " ";
    }
    cout << endl;

    //way 3
    vector<int> arr4={7, 8}; // vector arr4 of size 2 is created. first elt is 7, second is 8.
    for(auto i : arr4)
    {
        cout << i << " ";
    }
    cout << endl;
    
    //way 4
    vector<int> dupVec(arr); //all values of vector arr are copied in this vector dupVec.
    for(auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    //arr.front() gives us first element of vector.
    cout << "The first element of vector arr is: " << arr.front();
    cout << endl;

    //arr.back() gives us last element of vector.
    cout << "The last element of vector arr is: " << arr.back();
    cout << endl;

    //arr.pop_back() deletes element at last index of vector.
    cout << "Array before pop_back(): " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    arr.pop_back();

    cout << "Array after pop_back(): " << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // arr.erase() -> works with iterators.
    for(auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    dupVec.erase(dupVec.begin()); //deletes the element the iterator is referring to. here it is the first element.
    for(auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    dupVec.erase(dupVec.begin() + 2); //deletes 3rd element [index 2].
    for(auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    // erase() works with range as well.
    dupVec.erase(dupVec.begin() + 2, dupVec.end()); 
    for(auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    // clear() deletes entire array.
    // empty () returns boolean value. true if there is no element in array. false if element present.
    arr3.clear();
    if(arr3.empty())
    {
        cout << "clear() worked" << endl;
    }

    // at(n) just works like arr[n].
    // arr = {1,2,3,4,5,6}
    cout << "The element at third index of arr: " << arr.at(3) << endl; // this is equivalent to printing arr[3].
    
    //swap() -> swaps the values of 2 vectors.
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8, 9, 10};
    cout << "Before swapping, v1: ";
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Before swapping, v2: ";
    for(auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    swap(v1,v2);
    
    cout << "After swapping, v1: ";
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After swapping, v2: ";
    for(auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    // insert() allows us to insert at particular index using iterators.
    vector<int> v3 = {7, 8, 6, 5};
    v3.insert(v3.begin(), 4); // this will add 4 at the beginning.
    for(auto i : v3)
    {
        cout << i << " ";
    }
    cout << endl;

    v3.insert(v3.begin() + 2, 9); // this will add 9 at the 2nd index (3rd element of v3)
    // this will also push all the further elements to the right by 1 position.
    for(auto i : v3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}