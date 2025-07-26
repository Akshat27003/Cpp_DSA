#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, move all the 0's to the end of the array. 
The relative order of the other elements must remain the same. This must be done in place, without making a copy of the array.


Examples:
(1)
Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation: Both the zeroes are moved to the end and the order of the other elements stay the same
Input: nums = [0, 0, 0, 1, 3, -2]
(2)
Output: [1, 3, -2, 0, 0, 0]
Explanation: All 3 zeroes are moved to the end and the order of the other elements stay the same
(3)
Input: nums = [0, 20, 0, -20, 0, 20]
Output:
[20, -20, 20, 0, 0, 0]

Constraints:
1 <= nums.length <= 10^5
-10^4 <=nums[i] <= 10^4


*/

void moveZeros(vector<int>& nums)
{
    int n = nums.size();
    vector<int> temp;
    // storing all non zero values in temp array.
    for(int i = 0; i < n; i++)
    {
        if(nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }

    // transferring back to the original nums array at the start.
    for(int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }
    
    // adding 0 at the remaining indexes.
    for(int i = temp.size(); i < n; i++)
    {
        nums[i] = 0;
    }
}
// TC: O(2N).
// Worst Case: SC: O(N) -> N size of temp array.

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
    
    moveZeros(nums);

    cout << "The Array after moving zeros to the end is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}