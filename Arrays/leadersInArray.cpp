#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return a list of all the leaders in the array.



A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. 
The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.


Examples:
(1)
Input: nums = [1, 2, 5, 3, 1, 2]
Output: [5, 3, 2]
Explanation: 2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]
(2)
Input: nums = [-3, 4, 5, 1, -4, -5]
Output: [5, 1, -4, -5]
Explanation: -5 is the rightmost element, -4 is the largest element in the index range [4, 5], 
1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]
(3)
Input: nums = [-3, 4, 5, 1, -30, -10]
Output:
[5, 1, -10]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

vector<int> leadersInArrayBrute(vector<int> nums)
{
    vector<int> answer;
    int n = nums.size();
    for(int i = 0; i < n; i++) // compare each index element
    {
        bool leader = true;
        for(int j = (i + 1); j < n; j++) // with each index element to the right
        {
            if(nums[j] >= nums[i]) // if at any point a greater value than current index elt is found.
            {
                leader = false; // it is not a leader.
                break;
            }
        }
        if(leader) // if all values to the the right are smaller.
        {
            answer.push_back(nums[i]);
        }
    }
    return answer;
}
// TC: O(N^2)
// SC: O(N) -> space used for returning answer


vector<int> leadersInArrayOptimal(vector<int> nums)
{
    vector<int> answer2;
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i = (n - 1); i >= 0; i--) // iterate from the end
    {
        if(nums[i] > maxi) // check each element with max element till that point
        {
            answer2.push_back(nums[i]); // if maximum elt at index i found, add it to answer2.
            maxi = nums[i]; // update maxi to the current index element.
        }
    }
    reverse(answer2.begin(), answer2.end()); // reverse the answer to get the original order of leaders.
    // as we had reverse iterated.
    return answer2;

}
// TC: O(N).
// SC: O(N) -> for returning answer.

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

    vector<int> leaders = leadersInArrayBrute(nums);
    vector<int> leaders2 = leadersInArrayOptimal(nums);
    cout << "The Leaders in the given array (using brute appraoch) are: " << endl;
    for(auto i : leaders)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "The Leaders in the given array (using optimal appraoch) are: " << endl;
    for(auto i : leaders2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}