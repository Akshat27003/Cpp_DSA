#include<bits/stdc++.h>
using namespace std;

/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.


Examples:
(1)
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.
(2)
Input : nums = [1, 2, 1, 4, 5]
Output : false
Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
(3)
Input : nums = [1,9,6,8,5,4,0]
Output:
false

Constraints:
1 <= n <= 100
1 <= nums[i] <= 100

*/


bool isArraySorted(int i, int n, vector<int>& nums)
{
    if(i >= (n - 1))
    {
        return true;
    }
    if(nums[i] > nums[i + 1])
    {
        return false;
    }
    return isArraySorted(i + 1, n, nums);
}

bool isSorted(vector<int>& nums){
    int n = nums.size();
    return isArraySorted(0, n, nums);
}
// TC: O(N), SC:O(N)

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements in the array: " <<  endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The array is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    if(isSorted(nums))
    {
        cout << "The given array is SORTED in NON DECREASING ORDER." << endl;
    }
    else
    {
        cout << "The given array is NOT SORTED in NON DECREASING ORDER." << endl;
    }
    return 0;
}