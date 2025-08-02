#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.


Examples:
(1)
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation: nums[0] + nums[1] = 1 + 6 = 7
(2)
Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]
Explanation: nums[1] + nums[5] = 3 + (-3) = 0
(3)
Input: nums = [-6, 7, 1, -7, 6, 2], target = 3
Output:
[2, 5]

Constraints:
2 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
-10^5 <= target <= 10^5
Only one valid answer exists.

*/

// brute: pick 2 elements and check if they equal to sum. 
// if yes, add their index to vector and return the vector.

vector<int> twoSumBrute(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = (i + 1); j < n; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
// TC: O(N^2)
// sC: O(1)

// Better: use hashing to store element and index in map.
// while traversing in array check each element and if target - the current element gives an element from map.
// we return the index from the map and the index of curr element.
vector<int> twoSumBetter(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    map<int, int> mpp;
    for(int i = 0; i < n; i++)
    {
        int a = nums[i];
        int b = target - a;
        // if such b exists.. find wont return mpp.end().
        if(mpp.find(b) != mpp.end())
        {
            ans.push_back(mpp[b]);
            ans.push_back(i);
            return ans;
        }
        mpp[a] = i;
    }
    return {-1, -1};
}
// TC: O(N*logN) -> ordered map. searching/finding in ordered map takes logarithmic time.
// O(N) -> unordered map. searching/finding in unordered map takes O(1) time for avg and best case.
// SC: O(N)

// Optimal: 2 pointer:
// i at start, j at end
// sort array.
// compare ith and jth with target.
// if target == ith and jth return i,j
// if target < ith + jth elt, j--
// if target > ith + jth elt, i++
// this is useful to return the elements summing up to target or 
// to return true false in case of determining whether such pair of elements adding up to target exist or not.
bool twoSumOptimal(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    while(i < j)
    {
        int sum = nums[i] + nums[j];
        if(sum == target)
        {
            return true;
        }
        else if(sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
// TC: O(N) + O(NlogN) -> for iterating through array once and for sorting.
// sC: O(1).

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
    cout <<"The Array is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    int target;
    cout << "Enter target sum: " << endl;
    cin >> target;
    vector<int> ans = twoSumBrute(nums, target);
    vector<int> ans2 = twoSumBetter(nums, target);
    cout << "The index of the elements (using Brute Force Approach) in the nums array whose sum is equal to " << target << " is: [" << ans[0] << ", " << ans[1] << "]." << endl;
    cout << "The index of the elements (using Better Approach) in the nums array whose sum is equal to " << target << " is: [" << ans2[0] << ", " << ans2[1] << "]." << endl;
    if(twoSumOptimal(nums, target))
    {
        cout << "Pair of elements (using Optimal Approach) adding upto target value EXISTS in nums array." << endl;
    }
    else{
        cout << "Pair of elements (using Optimal Approach) adding upto target value DOES NOT EXIST in nums array." << endl;
    }
    cout << endl;
    return 0;
}