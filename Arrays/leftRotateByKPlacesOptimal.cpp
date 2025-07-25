#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.


Examples:
(1)
Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: nums = [3, 4, 5, 6, 1, 2]
Explanation: 
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
(2)
Input: nums = [3, 4, 1, 5, 3, -5], k = 8
Output: nums = [1, 5, 3, -5, 3, 4]
Explanation: 
rotate 1 step to the left: [4, 1, 5, 3, -5, 3]
rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]
rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]
rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]
rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]
rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]
rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]
rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
(3)
Input: nums = [1, 2, 3, 4, 5], k = 4
Output:
[5, 1, 2, 3, 4]
*/

void leftRotate(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + k); // reverse first k elements.
    reverse(nums.begin() + k, nums.end()); // reverse remaining (n-k) elements.
    reverse(nums.begin(), nums.end()); // reverse entire array again.
}
// TC: O(2*N).
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
    int k;
    cout << "Enter value by which Array to be left rotated: " << endl;
    cin >> k;
    leftRotate(nums, k);
    cout << "The Array after Left Rotate by " << k << " places is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}