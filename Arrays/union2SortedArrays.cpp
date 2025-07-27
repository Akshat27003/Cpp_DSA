#include<bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. 
The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


Examples:
(1)
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2
(2)
Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
(3)
Input: nums1 = [3, 4, 4, 4], nums2 = [6, 7, 7]
Output:
[3, 4, 6, 7]

Constraints:
1 <= nums1.length, nums2.length <= 1000
-10^4 <= nums1[i] , nums2[i] <= 10^4
Both nums1 and nums2 are sorted in non-decreasing order

*/

vector<int> unionBrute(vector<int> nums1, vector<int> nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    // take ordered set -> stores unique elements in sorted order.
    set<int> st;
    // iterate through 1st array and add elements in the set.
    for(int i = 0; i < n1; i++)
    {
        st.insert(nums1[i]);
    }
    // iterate through 2nd array and add elements in the set.
    for(int i = 0; i < n2; i++)
    {
        st.insert(nums2[i]);
    }

    // transfer the values of set into a vector as the return type is vector.
    vector<int> unionArr(st.size());
    int index = 0;
    for(auto itr : st)
    {
        unionArr[index] = itr;
        index++;
    }
    return unionArr; 
}
// TC: O(N1logN) + O(N2logN) + O(N1+N2)
// SC: O(N1 + N2) + O(N1 + N2) -> storing set and then returning answer vector.

vector<int> unionOptimal(vector<int> nums1, vector<int> nums2)
{
    int i = 0;
    int j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> unionArr;
    // till elements are there in both.
    while(i < n1 && j < n2)
    {
        if(nums1[i] <= nums2[j]) // element of 1st array lesser than 2nd array.
        {
            if(unionArr.size() == 0 || unionArr.back() != nums1[i]) // if union is empty
            // or the last element doesnt match with current element of nums1.
            {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        else // 2nd array element is lesser.
        {
            if(unionArr.size() == 0 || unionArr.back() != nums2[j])
            // if union is empty
            // or the last element doesnt match with current element of nums1.
            {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
    }
    // elements left only in nums1 array.
    while(i < n1)
    {
        if(unionArr.size() == 0 || unionArr.back() != nums1[i])
        {
            unionArr.push_back(nums1[i]);
        }
        i++;
    }
    // elements left only in nums2 array.
    while(j < n2)
    {
        if(unionArr.size() == 0 || unionArr.back() != nums2[j])
        {
            unionArr.push_back(nums2[j]);
        }
        j++;
    }
    return unionArr;
}
// TC: O(N1 + N2)
// SC: O(N1 + N2) -> for returning answer vector.

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
    vector<int> answer = unionBrute(nums1, nums2);
    vector<int> answer2 = unionOptimal(nums1, nums2);

    cout << "The UNION of the 2 arrays using Brute Approach is: " << endl;
    for(auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The UNION of the 2 arrays using Optimal Approach is: " << endl;
    for(auto i : answer2)
    {
        cout << i << " ";
    }
    return 0;
}