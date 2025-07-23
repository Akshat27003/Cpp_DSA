#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.



A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.


Examples:
(1)
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.
(2)
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
Explanation: 1 <= 1 <= 4 <= 4 <= 5.
Thus the array is sorted in non-decreasing order.
(3)
Input: nums = [3, 2, 3, 4, 5]
Output:
[2, 3, 3, 4, 5]

Constraints:
1 <= nums.length <= 106
-10^4 <= nums[i] <= 10^4
nums[i] may contain duplicate values.
*/

void merge(vector<int>& nums, int low, int mid, int high)
{
    vector<int> temp; // temporary array to store sorted values.
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high) // till elements exists in both arrays merging.
    {
        if(nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid) // if array from mid+1 to high is done
    {
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high) // if array from low to mid is done
    {
        temp.push_back(nums[right]);
        right++;
    }

    for(int i = low; i <= high; i++) // transferring temp array values into the right indexes in the main array.
    {
        nums[i] = temp[i - low];
    }  
}

void mergeSortHelper(vector<int>& nums, int low, int high)
{
    if(low >= high) //base condition for dividing array.
    {
        return; // low>=high means array is completely divided into single elements.
    }

    int mid = (low + high) / 2;
    mergeSortHelper(nums, low, mid); // dividing into 2 halves using indexes and specifically using mid index.
    mergeSortHelper(nums, mid + 1, high); // dividing into 2 halves using indexes and specifically mid index.

    merge(nums, low, mid, high); // passing to merge function which will sort each array internally.
}

vector<int> mergeSort(vector<int>& nums)
{
    int n = nums.size();
    mergeSortHelper(nums, 0, n - 1); // passing the entire array into mergeSort function initially.
    return nums;
}
// TC: O(Nlog2(N))
// SC: O(N)

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The elements of the array before sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    nums = mergeSort(nums);
 
    cout << "The elements of the array after sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;      
    return 0;
}