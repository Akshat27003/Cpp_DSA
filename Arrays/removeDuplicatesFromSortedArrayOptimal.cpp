#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so 
that each unique element appears only once. Return the number of unique elements in the array.



If the number of unique elements be k, then,

Change the array nums such that the first k elements of nums contain the unique values in the 
order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.


An array sorted in non-decreasing order is an array where every element to the right of an 
element is either equal to or greater in value than that element.


Examples:
(1)
Input: nums = [0, 0, 3, 3, 5, 6]
Output: 4
Explanation: Resulting array = [0, 3, 5, 6, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.
(2)
Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
Output: 4
Explanation: Resulting array = [-2, 2, 4, 5, _, _, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.
(3)
Input: nums = [-30, -30, 0, 0, 10, 20, 30, 30]
Select the possible resulting array.
Output:
[-30, 0, 10, 20, 30, _, _, _]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.


*/

int removeDuplicates(vector<int>& nums)
{
    // using 2 pointers
    int n = nums.size();
    int i = 0;
    for(int j = 1; j < n; j++)
    {
        if(nums[j] != nums[i]) // element is unique.
        {
            nums[i + 1] = nums[j]; // shifting it to the position next to current unique element.
            i++; //updating the index of current unique element by 1.
        }
    }
    // if we have unique elements from index 0 to index i. Total unique elements are i+1.
    return (i + 1);
}
// TC: O(N).
// SC: O(1).

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The Array is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    
    int targetIndex = removeDuplicates(nums);

    cout << "The Array after removing duplicates from the sorted array is: " << endl;
    for(int i = 0; i < targetIndex; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}