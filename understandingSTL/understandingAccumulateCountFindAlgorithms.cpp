#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {6, 2, 1, 7, 0};
    //accumulate() Algorithm
    //gives the sum of elements of the container based on the requirement.
    //accumulate(startPoint,endPoint,valueToWhichSumToBeAdded).
    int sum = accumulate(v1.begin(), v1.end(), 0);
    /*
    accumulate works like this:
    it initially takes sum as 0.
    iterates through specified positions and adds their value to initial sum which is 0 here.
    */
    cout << "The sum of all elements of vector v1 is: " << sum << endl;

    int sumOfFirstThreeElts = accumulate(v1.begin(), v1.begin() + 3, 0); 
    //the element iterator v1.begin()+3 is at in the above code is not included in summation.
    cout << "The sum of first 3 elts of vector v1 is: " << sumOfFirstThreeElts << endl;

    int sum2 = accumulate(v1.begin(), v1.end() - 2, 2); //initial sum in this case will be 2.
    cout << sum2 << endl;

    //count() Algorithm
    // returns the no. of times a number occurs in array / vector and likewise container.
    // count(startPoint,endPoint,numberToCheck).
    vector<int> v2 = {6, 2, 1, 2, 0, 7, 7, 7};
    cout << "6 appears: " << count(v2.begin(), v2.end(), 6) << " times." << endl;
    cout << "2 appears: " << count(v2.begin(), v2.end(), 2) << " times." << endl;
    cout << "1 appears: " << count(v2.begin(), v2.end(), 1) << " times." << endl;
    cout << "0 appears: " << count(v2.begin(), v2.end(), 0) << " times." << endl;
    cout << "7 appears: " << count(v2.begin(), v2.end(), 7) << " times." << endl;

    //find() Algorithm -> different from inbuilt member function find() for some container.
    //returns an iterator to first occurrence of the element specified. if not present, returns vector.end().
    vector<int> v3 = {6, 2, 1, 1, 0};
    auto it = find(v3.begin(), v3.end(), 2);
    cout << *it << endl;
    auto it2 = find(v3.begin(), v3.end(), 5);
    if(it2 == v3.end())
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}