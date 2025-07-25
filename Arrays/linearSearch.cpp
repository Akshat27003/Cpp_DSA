#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1


Examples:
(1)
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation: The first occurence of 3 in nums is at index 1
(2)
Input: nums = [2, -4, 4, 0, 10], target = 6
Output: -1
Explanation: The value 6 does not occur in the array, hence output is -1
(3)
Input: nums = [1, 3, 5, -4, 1], target = 1
Output:
0

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
-10^4 <= target <= 10^4


*/

// iterating linearly through a container to find something is linear search.
// it works with unsorted arrays as well.
int linearSrch(vector<int> nums, int target)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// Best Case TC: O(1) -> element found at first index.
// Worst Case TC: O(N) -> element not found.
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
    int target;
    cout << "Enter element to find in the array: " << endl;
    cin >> target;

    int targetIndex = linearSrch(nums, target);
    if(targetIndex == -1)
    {
        cout << "The element is not present in the array!" << endl;
    }
    else
    {
        cout << "The element found at index: " << targetIndex << endl;
    }

    return 0;
}