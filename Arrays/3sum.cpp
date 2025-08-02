#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums. Return all triplets such that:

i != j, i != k, and j != k
nums[i] + nums[j] + nums[k] == 0.


Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. 
The output and the triplets can be returned in any order.


Examples:
(1)
Input: nums = [2, -2, 0, 3, -3, 5]
Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]
Explanation: nums[1] + nums[2] + nums[0] = 0
nums[4] + nums[1] + nums[5] = 0
nums[4] + nums[2] + nums[3] = 0
(2)
Input: nums = [2, -1, -1, 3, -1]
Output: [[-1, -1, 2]]
Explanation: nums[1] + nums[2] + nums[0] = 0
Note that we have used two -1s as they are separate elements with different indexes
But we have not used the -1 at index 4 as that would create a duplicate triplet
(3)
Input: nums = [8, -6, 5, 4]
(Give answer with the output and triplets sorted in ascending order)
Output:
[]

Constraints:
1 <= nums.length <= 3000
-10^4 <= nums[i] <= 10^4


*/

// brute: pick 3 elements and check if they equal to 0. 
// if yes, add these elements as a triplet vector
// and return the vector containing all triplets.
vector<vector<int>> threeSumBrute(vector<int> nums)
{
    set<vector<int>> st; // set so that only unique triplets are added.
    int n = nums.size();
    for(int i = 0; i < (n - 2); i++)
    {
        for(int j = (i + 1); j < (n - 1); j++)
        {
            for(int k = (j + 1); k < n; k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // sorting so that unique elements order becomes the same.
                    st.insert(temp); // insert temp into set.
                    // set stores unique elements only.
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); // add all elements of set to vector
    return ans; // return vector.
}
// TC: O(N^3)* O(log(no_of_unique_triplets))
// SC: O(2*no_of_unique_triplets)

// Better: use hashing to store element in set.
// while traversing in array check elt = - nums[i] - nums[j] exists in set.
// if yes, store nums[i], nums[j] and the elt in the set.
//at the end after storing all triplets return the vector of all triplets.
vector<vector<int>> threeSumBetter(vector<int> nums)
{
    set<vector<int>> st;
    int n = nums.size();
    for(int i = 0; i < (n - 1); i++)
    {
        set<int> hashSet;
        for(int j = (i + 1); j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if(hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// TC: O(N^2*log(no_of_unique_triplets))
// SC: O(N) + O(2*no_of_unique triplets) -> O(N) for hashSet.

// Optimal: 3 pointers:
// i=0, j at i+1, k=n-1.
// sort array.
// compare ith, jth, kth with 0.
// if ith, jth, kth element sums up to 0, add to vector.
// fix i, operate on j and k pointers.
// if ith, jth, kth element > 0, k--.
// if ith, jth, kth element < 0, j++.
// after j and k cross each other. update i to next distinct value from the previous value of i.
// at the end return the vector containing all triplets.
vector<vector<int>> threeSumOptimal(vector<int> nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while(j < k)
        {
            int sum = nums[i];
            sum += nums[j];
            sum += nums[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while(j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
// TC: O(NlogN) + O(N^2).
// SC: O(no_of_unique_elements).

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

    vector<vector<int>> ans = threeSumBrute(nums);
    vector<vector<int>> ans2 = threeSumBetter(nums);
    vector<vector<int>> ans3 = threeSumOptimal(nums);
    cout << "The unique triplets pairs in the nums array whose sum is equal to 0 are (using brute approach): " << endl;
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "The unique triplets pairs in the nums array whose sum is equal to 0 are (using better approach): " << endl;
    for(auto i : ans2)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "The unique triplets pairs in the nums array whose sum is equal to 0 are (using optimal approach): " << endl;
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