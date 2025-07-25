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

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
0 <= k <= 10^5

*/

void leftRotate(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n; // to make k lesser than n.
    vector<int> temp;
    for(int i = 0; i < k; i++) // add first k elements to temp vector.
    {
        temp.push_back(nums[i]);
    }

    // shifting remaining n-k elements to the left by k places.
    for(int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    }

    // add k elements of temp array at the end.
    for(int i = (n - k); i < n; i++)
    {
        nums[i] = temp[i - (n - k)];
    }
}
// TC: O(N) + O(K) -> K: size of temp vector. 
// SC: O(K) -> K: Extra space used by temp vector.

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
    return 0;
}