#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

Examples:
(1)
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.
(2)
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
Explanation: 1 <= 1 <= 4 <= 4 <= 5.
Thus the array is sorted in non-decreasing order.
(3)
Input: nums = [3, 2, 3, 4, 5]
Output:
[2, 3, 3, 4, 5]

Constraints:
1 <= nums.length <= 1000
-104 <= nums[i] <= 104
nums[i] may contain duplicate values.



*/

vector<int> insertion(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0; i <= (n - 1); i++)
    {
        int j = i;
        while(j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
    return nums;
}
// TC: O(N^2) -> avg and worst case.
// TC: O(N) -> best case (nearly sorted arrays).
// SC: O(1).

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The elements of the array before sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    nums = insertion(nums);
 
    cout << "The elements of the array after sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;   
    return 0;
}