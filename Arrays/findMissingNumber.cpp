#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), 
return the only number missing from the array within this range.


Examples:
(1)
Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation: nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]
(2)
Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]
(3)
Input: nums = [1, 3, 6, 4, 2, 5]
Output:
0

Constraints:
n == nums.length
1 <= n <= 10^4
0 <= nums[i] <= n
All the numbers of nums are unique.


*/

// Brute: Take every number in range [0,n] and search for it in given array
int missingNumInArrBrute(vector<int> nums)
{
    int n = nums.size();
    for(int i = 0; i <= n; i++) // loop for all elements of range.
    {
        bool flag = false; // to check if current element at hand is present or not.
        for(int j = 0; j < n; j++) // loop to iterate through the array.
        {
            if(nums[j] == i) // if element i is present in array.
            {
                flag = true; 
                break;
            }
        }
        if(!flag) // for whatever value of i flag doesnt become true is the element not present in the array.
        {
            return i;
        }
    }
}
// TC: O(N^2).
// SC: O(1).

// using hashing
int missingNumInArrBetter(vector<int> nums)
{
    int n = nums.size();
    int hash[n + 1] = {0}; // initializing hash array with all 0s.
    for(int i = 0; i < n; i++)
    {
        hash[nums[i]] = 1; // mark all indexes that occur in nums as 1.
    }
    for(int i = 0; i < (n + 1); i++)
    {
        if(hash[i] == 0) // whichever value is 0 in the hash array. 
        {
            return i; // the corresponding value of i is the one which doesnt occur in nums.
        }
    }
}
// TC: O(2N)
// TC: O(N)


// using summation
int missingNumInArrOptimal1(vector<int> nums)
{
    int n = nums.size();
    int sum1 = (n * (n + 1)) / 2; // formula of summation.
    // calculating sum of elements by iterating through the array
    int sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        sum2 += nums[i];
    }
    // the difference between sum1 and sum2 would give us the num missing from nums array.
    return (sum1 - sum2);
}
// TC: O(N).
// SC: O(1).

// using XOR property.
// xor of same num is 0.
// xor of any num with 0 is then num itself.
// bitwise operators are a bit faster
// no chance of overflow of value.
// xor cant be greater than the greatest number.
int missingNumInArrOptimal2(vector<int> nums)
{
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ nums[i];
        xor2 = xor2 ^ (i + 1);
    }
    return (xor1 ^ xor2);
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
    
    int element = missingNumInArrBrute(nums);
    int element2 = missingNumInArrBetter(nums);
    int element3 = missingNumInArrOptimal1(nums);
    int element4 = missingNumInArrOptimal2(nums);
    cout << "The element missing in the range [0, " << n << "] using Brute Approach is: " << element << endl;
    cout << "The element missing in the range [0, " << n << "] using Better Approach is: " << element2 << endl;
    cout << "The element missing in the range [0, " << n << "] using Optimal Approach 1 is: " << element3 << endl;
    cout << "The element missing in the range [0, " << n << "] using Optimal Approach 2 is: " << element4 << endl;    
    return 0;
}