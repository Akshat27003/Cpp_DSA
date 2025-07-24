#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.



A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.


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
1 <= nums.length <= 105
-10^4 <= nums[i] <= 10^4
nums[i] may contain duplicate values.


*/

int pivot(vector<int>& nums, int low, int high)
{
    int pivot = nums[low]; // taking the first elt as pivot.
    int i = low; // pointer to left most index.
    int j = high; // pointer to right most index.

    while(i < j)
    {
        // stop i pointer at an index where the element is greater than our current pivot elt.
        while(nums[i] <= pivot && i < high) // i < high is important so that we dont go out of bound in any edge case.
        // one edge case is when all elements are equal.
        {
            i++; // nums[i] <= pivot means we are keeping equal value to the left of partition index.
        }
        // stop j pointer at the index where the element is less than our current pivot elt.
        // so that when swap ith and jth index element. lesser val element comes to the left and 
        // greater value elements goes to the right.
        while(nums[j] > pivot && j > low) // j > low is important so that we dont go out of bound in any edge case.
        // one edge case is when all elements are equal.
        {
            j--;
        }
        if(i < j)
        {
            swap(nums[i], nums[j]); // till i doesnt cross j, we can swap to get lesser elt to the left and greater to the right.
        }
    }
    swap(nums[j], nums[low]); // placing pivot element at its correct index.
    return j;
}

void quickSortHelper(vector<int>& nums, int low, int high)
{
    // if 1 element left, it is already sorted. we dont do anything.
    if(low < high) // condition ensuring more than 1 element are there.
    {
        // the pivot function will find pivot element. place it at correct index.
        // put all elements lesser than it to the left and all elements greater to the right.
        // returns the index where the pivot element was correctly placed. this is the partition index.
        int partitionIndex = pivot(nums, low, high);
        // passing the  left and right array w.r.t to the Partition Index.
        quickSortHelper(nums, low, partitionIndex - 1);
        quickSortHelper(nums, partitionIndex + 1, high);
    }
}

vector<int> quickSort(vector<int>& nums)
{
    int n = nums.size();
    quickSortHelper(nums, 0, n - 1); // passing 0 as low and n-1 as high initially.
    return nums;
}
// Best, Avg Case TC: O(Nlog2(N)). Worst Case TC: O(N^2).
// Best, Avg Case SC: O(1) + O(log2(N)). Worst Case SC: O(1) + O(N) -> O(N) and O(log2(N)) is for recursive stack space
// We can ignore O(1)... Best, Avg Case SC: O(log2(N)). Worst Case SC: O(N).



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

    nums = quickSort(nums);
 
    cout << "The elements of the array after sorting are: " << endl;
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl; 
    return 0;
}