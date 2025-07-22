#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.



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
-10^4 <= nums[i] <= 10^4
nums[i] may contain duplicate values.


*/

vector<int> bubble(vector<int>& nums)
{
    int n = nums.size();
    for(int i = (n - 1); i >= 1; i--) // reverse traversal
    {
        bool didSwap = false;
        for(int j = 0; j < i;  j++) //0th index to last, then secondlast... till 1st index.
        {
            if(nums[j] > nums[j + 1]) //compare adjacent
            {
                swap(nums[j], nums[j + 1]); // swap if jth index elt is greater tha (j+1)th index elt.
                didSwap = true;
            }
        }
        if(didSwap == false) // if already sorted (if no swapping done), break out of further iterations.
        {
            break;
        }
    }
    return nums;
}
// TC: O(N^2) -> worst case, average case.
// TC: O(N) -> best case (already sorted array or nearly sorted array).
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

    nums = bubble(nums);
 
    cout << "The elements of the array after sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;   
    return 0;
}