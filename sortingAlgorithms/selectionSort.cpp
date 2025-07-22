#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.



A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.


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

vector<int> selection(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0; i <= (n - 2); i++) // loop to iterate through array and maintain the sorted element at the ith index.
    {
        int mini = i;
        for(int j = i; j <= (n - 1); j++) // loop to get the min element from unsorted portion of array.
        {
            if(nums[j] < nums[mini])
            {
                mini = j;
            }
        }
        // swapping mini index element with the element at ith index.
        swap(nums[mini], nums[i]);
    }
    return nums;
}
// TC: O(N^2) -> best, avg, worst case. SC: O(1).
// Even if array is completely sorted, it has to be sure of min elt in each iteration and self swap at the end.

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

    nums = selection(nums);
 
    cout << "The elements of the array after sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;   
    return 0;
}