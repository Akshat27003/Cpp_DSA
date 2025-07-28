#include<iostream>
#include<vector>
using namespace std;

/*
Given an M * N matrix, print the elements in a clockwise spiral manner. Return an array with the elements in 
the order of their appearance when printed in a spiral manner.


Examples:
(1)
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
Explanation: The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5
(2)
Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]
Output: [1, 2, 3, 4, 8, 7, 6, 5]
Explanation: The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5
(3)
Input: matrix = [[1, 2], [3, 4], [5, 6], [7, 8]]
Output:
[1, 2, 4, 6, 8, 7, 5, 3]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100


*/

vector<int> spiralMatrixFrom2DArr(vector<vector<int>> nums)
{
    int m = nums.size();
    int n = nums[0].size();
    int top = 0;
    int left = 0;
    int right = n - 1;
    int bottom = m - 1;
    int cnt = m * n;
    vector<int> answer;
    while(left <= right && top <= bottom)
    {
        // top row
        for(int i = left; i <= right; i++)
        {
            if(cnt > 0)
            {
                answer.push_back(nums[top][i]);
                cnt--;
            }
        }
        top++;

        // right col
        for(int i = top; i <= bottom; i++)
        {
            if(cnt > 0)
            {
                answer.push_back(nums[i][right]);
                cnt--;
            }
        }
        right--;

        // bottom row
        for(int i = right; i >= left; i--)
        {
            if(cnt > 0)
            {
                answer.push_back(nums[bottom][i]);
                cnt--;
            }
        }
        bottom--;

        // left col
               
        for(int i = bottom; i >= top; i--)
        {
            if(cnt > 0)
            {
                answer.push_back(nums[i][left]);
                cnt--;
            }
        }
        left++;
    }
    return answer;
}
// TC: O(M*N).
// SC: O(M*N).

int main()
{
    int m;
    cout << "Enter no of rows: " << endl;
    cin >> m;
    int n;
    cout << "Enter no of cols: " << endl;
    cin >> n;
    vector<vector<int>> nums(m, vector<int> (n));
    cout << "Enter values into the 2D Array: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    cout << "The 2D Array is: " << endl;
    for(auto i : nums)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> spiralForm = spiralMatrixFrom2DArr(nums);
    cout << "Printing matrix in spiral form: " << endl;
    for(auto i : spiralForm)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}