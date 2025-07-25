#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.


Examples:
(1)
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7
(2)
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned
(3)
Input: nums = [7, 7, 2, 2, 10, 10, 10]
Output:
7

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
nums may contain duplicate elements.


*/

int secondLargestEltInArrayBrute(vector<int> nums)
{
    sort(nums.begin(), nums.end()); // sort nums in ascending order.
    int n = nums.size();
    int largest = nums[n - 1]; // after sort, largest will be the last.
    for(int i = (n - 2); i >= 0; i--)
    {
        if(nums[i] != largest) // if 2nd last to 1st element. any elt is not equal (lesser) to largest, return that element.
        {
            return nums[i];
        }
    }
    return -1; // if no secondLargest element exists.
}
// TC: O(Nlog(N)) + O(N)
// SC: O(1)

int secondLargestEltInArrayBetter(vector<int> nums)
{
    // iterate array first to get largest element.
    int largest = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++)
    {
        if(nums[i] > largest)
        {
            largest = nums[i];
        }
    }

    // iterate array again to get second largest element if it exists.
    int sLargest = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > sLargest && nums[i] != largest)
        {
            sLargest = nums[i];
        }
    }
    if(sLargest == INT_MIN)
    {
        sLargest = -1;
    }
    return sLargest;
}
// TC: O(2*N)
// SC: O(1)

int secondLargestEltInArrayOptimal(vector<int> nums)
{
    int largest = nums[0];
    int sLargest = INT_MIN;
    int n = nums.size();
    for(int i = 1; i < n; i++)
    {
        if(nums[i] > largest)
        {
            sLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] < largest && nums[i] > sLargest)
        {
            sLargest = nums[i];
        }
    }
    if(sLargest == INT_MIN)
    {
        sLargest = -1;
    }
    return sLargest;
}
// TC: O(N)
// SC: (1)

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
    int secondLargest = secondLargestEltInArrayBrute(nums);
    int secondLargest2 = secondLargestEltInArrayBetter(nums);
    int secondLargest3 = secondLargestEltInArrayOptimal(nums);
    if(secondLargest == -1)
    {
        cout << "Second Largest Element DOES NOT EXIST!" << endl;
    }
    else{
        cout << "The largest element of the given Array is (using Brute Approach): " << secondLargest << endl;
    }

    if(secondLargest2 == -1)
    {
        cout << "Second Largest Element DOES NOT EXIST!" << endl;
    }
    else{
        cout << "The largest element of the given Array is (using Better Approach): " << secondLargest2 << endl;
    }
    
    if(secondLargest3 == -1)
    {
        cout << "Second Largest Element DOES NOT EXIST!" << endl;
    }
    else{
        cout << "The largest element of the given Array is (using Optimal Approach): " << secondLargest3 << endl;
    }
    return 0;
}