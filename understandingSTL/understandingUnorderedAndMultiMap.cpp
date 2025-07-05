#include<bits/stdc++.h>
using namespace std;

int main()
{
    //unordered map stores key value pairs only.
    //not in any order.
    //unique keys are there.
    //unordered maps mostly have better time complexity for different operations.

    //declaring unordered_map.
    unordered_map<int, string> mpp; //empty container.
    mpp[1] = "abc"; //first way of adding key value pair
    mpp.insert({2, "bcd"}); //second way
    mpp.emplace(3, "cde"); //third way

    //printing elements, random order.
    for(auto itr : mpp)
    {
        cout << "{" << itr.first << ", " << itr.second << "}" << endl;
    }
    cout << endl;

    //multimap stores key value pairs as well.
    //in ascending order of keys.
    //keys can be repeated. they need not be unique.

    //declaring multimap
    multimap<int, string> mpp2; //empty container.

    //adding elements.
    // mpp2[1] = "abc"; not allowed
    mpp2.insert({1, "abc"});
    mpp2.insert({1, "bcd"});
    mpp2.insert({1, "abc"});
    mpp2.emplace(2, "cde");
    mpp2.emplace(2, "cde");
    mpp2.emplace(2, "def");
    mpp2.emplace(3, "efg");

    //printing elements, ascending order of keys.
    for(auto itr : mpp2)
    {
        cout << "{" << itr.first << ", " << itr.second << "}" << endl;
    }    

    cout << endl;

    //equal_range() -> returns a pair of iterators.
    // first iterator is to the first occurrence of the key and its value.
    // second iterator is to 1 past the last occurrence of the key and its value.
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> itr = mpp2.equal_range(2); // pair of iterators.
    //printing all elements in the given range
    for(multimap<int, string>::iterator i = itr.first; i != itr.second; i++)
    {
        cout << "{" << (*i).first << ", " << (*i).second << "}" << endl;        
    }

    cout << endl;

    auto itr2 = mpp2.equal_range(1);
    // auto here is same as pair<multimap<int, string>::iterator, multimap<int, string>::iterator>.
    for(auto i = itr2.first; i != itr2.second; i++)
    {
        cout << "{" << (*i).first << ", " << (*i).second << "}" << endl;        
    }    

    cout << endl;

    // its always better to use != and not <= with iterators.
    // != works always, <= works with some containers and not with other containers.
    // its not a good practice to usually use <= in general with iterators.

    return 0;
}