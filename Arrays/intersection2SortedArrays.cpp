#include<bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays. 
Each element in the result must appear as many times as it appears in both arrays.



The intersection of two arrays is an array where all values are present in both arrays.


Examples:
(1)
Input: nums1 = [1, 2, 2, 3, 5], nums2 = [1, 2, 7]
Output: [1, 2]
Explanation: The elements 1, 2 are the only elements present in both nums1 and nums2
(2)
Input: nums1 = [1, 2, 2, 3], nums2 = [4, 5, 7]
Output: []
Explanation: No elements appear in both nums1 and nums2
(3)
Input: nums1 = [-45, -45, 0, 0, 2], nums2 = [-50, -45, 0, 0, 5, 7]
Output:
[-45, 0, 0]

Constraints:
1 <= nums1.length, nums2.length <= 1000
-10^4 <= nums1[i], nums2[i] <= 10^4
Both nums1 and nums2 are sorted in non-decreasing order.

*/

vector<int> intersectionBrute(vector<int> nums1, vector<int> nums2)
{
    // compare each element of both arrays.
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> intersection;
    int visited[n2] = {0}; // to keep track of elements already found in both array.
    // so that they are not added again.
    for(int i = 0; i < n1; i++) // take each value of nums1 array.
    {
        for(int j = 0; j < n2; j++) // compare with each val of nums2 array.
        {
            if(nums1[i] == nums2[j] && visited[j] == 0)
            {
                intersection.push_back(nums2[j]);
                visited[j] = 1; // jth index visited and added.
                break;
            }
            if(nums2[j] > nums1[i])
            {
                break; // as the 2 arrays are sorted.
                // the first value greater than the value of ith index element
                // would mean there was no match found and it wont be found ahead as well.
            }
        }
    }
    return intersection;
    
}
// TC: O(N1*N2)
// SC: O(N2) + O(N) -> N2 -> size of visited array (used for solving). N size of returning vector (used for returning answer).

vector<int> intersectionOptimal(vector<int> nums1, vector<int> nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> intersection2;
    // we have to operate only till elements are there in both. 
    // if 1 element is traversed completely. we are done.
    while(i < n1 && j < n2)
    {
        if(nums1[i] < nums2[j]) // 1st array element less than 2nd array elt.
        {
            i++; // get to the next index of 1st array to compare this index val with nums2.
        }

        else if(nums2[j] < nums1[i]) // 2nd array element less than 1st array elt.
        {
            j++; // get to the next index of 2nd array to compare this index val with nums1.
        }
        else // if both array values match
        {
            intersection2.push_back(nums1[i]); // add it to answer intersection vector.
            i++; // move i to next index of nums1
            j++;  // move j to next index of nums2.
        }
    }
    return intersection2;
}
// TC: O(N1 + N2)
// TC: O(N1 + N2) -> only for returning and not solving.

int main()
{
    int n1;
    cout << "Enter size of array1: " << endl;
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of array1: " << endl;
    for(int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }

    cout << "The 1st Array is: " << endl;
    for(auto i : nums1)
    {
        cout << i << " ";
    }
    cout << endl;

    int n2;
    cout << "Enter size of array2: " << endl;
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of array2: " << endl;
    for(int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }

    cout << "The 2nd Array is: " << endl;
    for(auto i : nums2)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> answer = intersectionBrute(nums1, nums2);
    vector<int> answer2 = intersectionOptimal(nums1, nums2);

    cout << "The INTERSECTION of the 2 arrays using Brute Approach is: " << endl;
    for(auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The INTERSECTION of the 2 arrays using Optimal Approach is: " << endl;
    for(auto i : answer2)
    {
        cout << i << " ";
    }
    return 0;
}