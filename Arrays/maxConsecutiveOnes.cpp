#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array nums, return the maximum number of consecutive 1s in the array.



A binary array is an array that contains only 0s and 1s.


Examples:
(1)
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation: The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s
(2)
Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation: No 1s are present in nums, thus we return 0
(3)
Input: nums = [1, 0, 1, 1, 1, 0, 1, 1, 1]
Output:
3

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.


*/

int maximumConsecutiveOnes(vector<int> nums)
{
    int maxi = 0; // to have the max consecutive ones.
    int cnt = 0; // to maintain cnt of current consecutive ones.
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 1) // if the current element is 1.
        {
            cnt++; // update cnt by 1.
            if(cnt > maxi) // if cnt of current 1s is more than previous consecutive 1s.
            {
                maxi = cnt; // update max consecutive ones.
            }
        }
        else
        {
            cnt = 0; // if the current element is 0. reset cnt to 0 for next occurrence of 1.
        }
    }
    return maxi;
}
// TC: O(N), SC: O(1).

int main()
{
    int n;
    cout << "Enter size of binary Array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter 0s or 1s in the binary Array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "The binary Array is: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    int maxContOnes = maximumConsecutiveOnes(nums);
    cout << "Max consecutive 1s in the binary array is: " << maxContOnes << endl;
    return 0;
}