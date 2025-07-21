#include<bits/stdc++.h>
using namespace std;

/*
Given an array nums of n integers, return reverse of the array.


Examples:
(1)
Input : nums = [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]
(2)
Input : nums = [1, 3, 3, 3, 5]
Output : [5, 3, 3, 3, 1]
(3)
Input : nums = [1, 2, 1]
Output:
[1, 2, 1]

Constraints:
1 <= n <= 100
1 <= nums[i] <= 100

*/

void reverseArr(int left, int right, vector<int>& nums)
{
    if(left >= right)
    {
        return;
    }
    swap(nums[left], nums[right]);
    reverseArr(left + 1, right - 1, nums);
}

vector<int> reverseArray(vector<int>& nums)
{
    int n = nums.size();
    reverseArr(0, n - 1, nums);
    return nums;
}
// TC: O(N/2), SC: O(N/2).

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements in the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The array before reversal is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> reversedNums = reverseArray(nums);
    cout << "The array after reversal is: " << endl;
    for(auto i : reversedNums)
    {
        cout << i << " ";
    }
    cout << endl;    
    return 0;
}