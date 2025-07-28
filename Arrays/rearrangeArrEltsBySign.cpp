#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums of even length consisting of an equal number of positive and negative integers.


Return the answer array in such a way that the given conditions are met:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.

Examples:
(1)
Input : nums = [2, 4, 5, -1, -3, -4]
Output : [2, -1, 4, -3, 5, -4]
Explanation: The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions
(2)
Input : nums = [1, -1, -3, -4, 2, 3]
Output : [1, -1, 2, -3, 3, -4]
Explanation: The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions
(3)
Input: nums = [-4, 4, -4, 4, -4, 4]
Output:
[4, -4, 4, -4, 4, -4]

Constraints:
2 <= nums.length <= 10^5
1 <= | nums[i] | <= 10^4
nums.length is an even number.
Number of positive and negative numbers are equal.
*/

vector<int> rearrangeBySignBrute(vector<int> nums)
{
    int n = nums.size();
    vector<int> positive; // to add positive element of nums arr. it will have size (N/2).
    vector<int> negative; // to add negative elements of nums arr. it will also have size (N/2).
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }

    // traverse again and put positives from positive array at even index.
    // put negatives from negative array at odd index.
    for(int i = 0; i < (n / 2); i++)
    {
        nums[2 * i] = positive[i];
        nums[(2 * i) + 1] = negative[i];
    } 
    return nums;
}
// TC: O(N) + O(N)
// SC: O(N)

vector<int> rearrangeBySignOptimal(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0;
    int negIndex = 1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}
// TC: O(N)
// SC: O(N)

int main()
{
    int n;
    cout << "Enter size of Array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements in the Array: " << endl;
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

    vector<int> leaders = rearrangeBySignBrute(nums);
    vector<int> leaders2 = rearrangeBySignOptimal(nums);
    cout << "The rearranged array (using brute appraoch) acc to conditions given is: " << endl;
    for(auto i : leaders)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The rearranged array (using optimal appraoch) acc to conditions given is: " << endl;
    for(auto i : leaders2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}