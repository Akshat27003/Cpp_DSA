#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
·      a, b, c, d are all distinct valid indices of nums.
·      nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. 
One element can be a part of multiple quadruplets. 
The output and the quadruplets can be returned in any order.


Examples:
(1)
Input: nums = [1, -2, 3, 5, 7, 9], target = 7
Output: [[-2, 1, 3, 5]]
Explanation: nums[1] + nums[0] + nums[2] + nums[3] = 7
(2)
Input: nums = [7, -7, 1, 2, 14, 3], target = 9
Output: []
Explanation: No quadruplets are present which add upto 9
(3)
Input: nums = [1, 1, 3, 4, -3], target = 5
(Give answer with the output and quadruplets sorted in ascending order)
Output:
[[-3, 1, 3, 4]]

Constraints:
1 <= nums.length <= 200
-10^4 <= nums[i] <= 10^4
-10^4 <= target <= 10^4

*/

// brute: pick 4 elements and check if they equal to target. 
// if yes, add these elements as a quadruplet vector
// and return the vector containing all quadruplets.
vector<vector<int>> fourSumBrute(vector<int> nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i < (n - 3); i++)
    {
        for(int j = (i + 1); j < (n - 2); j++)
        {
            for(int k = (j + 1); k < (n - 1); k++)
            {
                for(int l = (k + 1); l < n; l++)
                {
                    int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// TC: O(N^4* log(no_of_unique_quadruplets))
// SC: O(2*no_of_unique_quadruplets)

// Better: use hashing to store element in set.
// while traversing in array check  target - nums[i] - nums[j] - nums[k] exists in set.
// if yes, store nums[i], nums[j], nums[k] and the elt in the set.
// at the end after storing all quadruplets return the vector of all quadruplets.
vector<vector<int>> fourSumBetter(vector<int> nums, int target)
{
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < (n - 2); i++)
    {
        for(int j = (i + 1); j < (n - 1); j++)
        {
            set<int>hashSet;
            for(int k = (j + 1); k < n; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int fourth = target - sum;
                if(hashSet.find(fourth) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// TC: O(N^3*log(no_of_unique_elements)).
// SC: O(N) + O(2*no_of_unique_quadruplets)

// Optimal: 4 pointers:
// i=0, j=i+1, k=j+1, l=n-1.
// sort array.
// compare ith, jth, kth, lth element with target.
// if ith, jth, kth,l th element sums up to target, add to vector.
// fix i, fix j.
// operate on k and l pointers.
// if ith, jth, kth, lth element sum > target, l--.
// if ith, jth, kth, lth element sum < target, k++.
// if quadruplet found, k++ till a new element is found.
// and l-- till new element is found.
// after k and l cross each other. 
// j increments when k and l cross.
// i increments when loop for j is executed.
//at the end after storing all quadruplets return the vector of all quadruplets.
vector<vector<int>> fourSumOptimal(vector<int> nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for(int j = (i + 1); j < n; j++)
        {
            if(j > (i + 1) && nums[j] == nums[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while(k < l)
            {
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum > target)
                {
                    l--;
                }
                else if(sum < target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while(k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}
// TC: O(N^3) + O(NlogN)
// SC: O(no_of_quadruplets).

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
    cout << "Enter target value: " << endl;
    cin >> target;
    vector<vector<int>> ans = fourSumBrute(nums, target);
    vector<vector<int>> ans2 = fourSumBetter(nums, target);
    vector<vector<int>> ans3 = fourSumOptimal(nums, target);

    cout << "The unique quadruplet pairs in the nums array whose sum is equal to " << target << " are (using brute approach): " << endl;
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "The unique quadruplet pairs in the nums array whose sum is equal to " << target << " are (using better approach): " << endl;
    for(auto i : ans2)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "The unique quadruplet pairs in the nums array whose sum is equal to " << target << " are (using optimal approach): " << endl;
    for(auto i : ans3)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}