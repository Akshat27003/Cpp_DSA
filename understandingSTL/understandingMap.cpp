#include<bits/stdc++.h>
using namespace std;

int main()
{
    // map stores data in the form of key value pairs.
    // keys must be unique.

    //declaration.
    map<int, string> mpp;
    
    //adding key value pairs.
    //mpp[key] = value;
    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp[3] = "cde";
    //another way.
    //mpp.insert({key,value});
    mpp.insert({4, "def"});

    //data is stored in the ascending order of keys.
    mpp.insert({0, "zab"}); //since the key is 0, this will be stored at the beginning.

    //printing the keys and corresponding values of the map.
    //stored in the form of pairs.
    for(auto it : mpp)
    {
        cout << "[" << it.first << ", " << it.second << "]" << endl;
    }
    
    //if multiple values are entered for a key, the last entered value is mapped with the key.
    mpp[5] = "fgh"; // this will be stored first.
    mpp[5] = "efg"; // this will replace the original value.
    cout << mpp[5] << endl;

    //using find with map.
    auto it = mpp.find(2); //this returns an iterator to the key value pair with key 2.
    cout <<(*it).first << ": " << (*it).second << endl;
    //if find() doesnt find any key matching with the key at hand, it returns iterator to mpp.end().
    auto itr2 = mpp.find(7);
    if(itr2 == mpp.end())
    {
        cout << "No key value pair exists for given key!" << endl;
    } 

    //mpp.emplace() adds value to corresponding keys like insert.
    //syntax bit different from insert().
    mpp.emplace(6, "fgh");
    for(auto it : mpp)
    {
        cout << "[" << it.first << ", " << it.second << "]" << endl;
    }

    //lower_bound() and upper_bound().
    //lower_bound() returns an iterators to the key value pair whose key >= given key.
    //upper_bound() returns an iterators to the key value pair whose key > given key.
    auto itr3 = mpp.lower_bound(4);
    cout << "Lower Bound: " << (*itr3).first << ", " << (*itr3).second << endl;
    auto itr4 = mpp.upper_bound(4);
    cout << "Upper Bound: " << (*itr4).first << ", " << (*itr4).second << endl;
    //lower_bound() returns mpp.end() in case given key > the greatest key in the map.
    //upper_bound() returns mpp.end() in case given key >= the greatest key in the map.
    auto itr5 = mpp.lower_bound(7); //here, 7 > greatest key in the map which is 6. this will return  mpp.end().
    if(itr5 == mpp.end())
    {
        cout << "Lower Bound does not exist!" << endl;
    }
    auto itr6 = mpp.upper_bound(6); //6 >= greatest key in the map which is 6. this will return mpp.end().
    if(itr6 == mpp.end())
    {
        cout << "Upper Bound does not exist!" << endl;
    }
    auto itr7 = mpp.lower_bound(6); // 6 is not greater than the greatest key 6 of the map mpp.
    // 6>=6 is true. so this wil give an iterator to the key value pair having key as 6.
    cout << "Lower Bound: " << (*itr7).first << ", " << (*itr7).second << endl;

    //lower_bound() and upper_bound() can be same or different.

    //any type of data possible in map. need not be int or string or char only.
    map<int,char> mpp2;
    //empty() returns true if no key value pair exists in a map. else, it returns false.
    if(mpp2.empty())
    {
        cout << "The given map is empty! " << endl;
    }
    mpp2.insert({1,'a'});
    if(!mpp2.empty())
    {
        cout<< "The given map is not empty! " << endl;
    }

    return 0;
}