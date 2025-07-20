#include<bits/stdc++.h>
using namespace std;

/*
Given an array nums, find the sum of elements of array using recursion.


Examples:
(1)
Input : nums = [1, 2, 3]
Output : 6
Explanation : The sum of elements of array is 1 + 2 + 3 => 6.
(2)
Input : nums = [5, 8, 1]
Output : 14
Explanation : The sum of elements of array is 5 + 8 + 1 => 14.
(3)
Input : nums = [12, 9, 17]
Output:
38

Constraints:
1 <= n <= 100
1 <= nums[i] <= 100
*/

int summ(vector<int>& nums, int i)
{
    if(i >= nums.size()) // base condition.
    {
        return 0;
    }
    return nums[i] + summ(nums, i + 1);
}

int arraySum(vector<int>& nums) // pass by reference
{
    return summ(nums, 0);
}
// TC: O(N), SC: O(N).


int main()
{
    int n;
    cout << "Enter size of vector: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of vector: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The array elements are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The sum of all the elements of the array is: " << arraySum(nums) << endl;
    return 0;
}