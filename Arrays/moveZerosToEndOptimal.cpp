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

// using 2 pointers approach
void moveZeros(vector<int>& nums)
{
    int n = nums.size();
    // finding out the index of first 0.
    int j = -1; // initialize as -1 to handle the case of no zero being there in the array.
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if(j == -1) // it means there is no 0 in array.
    {
        return;
    }

    // j will always point at an index where 0 is present 
    // i will point at non zero values and will be used to swap 0 with non zero values linearly.
    for(int i = (j + 1); i < n; i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
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
    
    moveZeros(nums);

    cout << "The Array after moving zeros to the end is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}