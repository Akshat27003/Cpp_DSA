#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, rotate the array to the left by one.



Note: There is no need to return anything, just modify the given array.


Examples:
(1)
Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation: Initially, nums = [1, 2, 3, 4, 5]
Rotating once to left -> nums = [2, 3, 4, 5, 1]
(2)
Input: nums = [-1, 0, 3, 6]
Output: [0, 3, 6, -1]
Explanation: Initially, nums = [-1, 0, 3, 6]
Rotating once to left -> nums = [0, 3, 6, -1]
(3)
Input: nums = [7, 6, 5, 4]
Output:
[6, 5, 4, 7]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4


*/

void leftRotate(vector<int>& nums)
{
    int temp = nums[0]; // take 1st index value as temp
    int n = nums.size();
    for(int i = 1; i < n; i++) // move elements from 1st index to the left by 1.
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = temp; // last index element to be the 1st index element stored in temp.
}
// TC: O(N)
// SC: O(1)

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

    leftRotate(nums);
    cout << "The Array after Left Rotate by 1 place: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}