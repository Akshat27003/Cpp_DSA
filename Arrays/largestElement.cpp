#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums, return the value of the largest element in the array


Examples:
(1)
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
(2)
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99
(3)
Input: nums = [-4, -3, 0, 1, -8]
Output:
1

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
nums may contain duplicate elements.


*/

int largestEltInArray(vector<int> nums)
{
    int largest = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++)
    {
        if(nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    return largest;
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
    int largest = largestEltInArray(nums);
    cout << "The largest element of the given Array is: " << largest << endl;
    return 0;
}