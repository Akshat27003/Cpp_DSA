#include<bits/stdc++.h>
using namespace std;

/*
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.



The rotation must be done in place, meaning the input 2D matrix must be modified directly.


Examples:
(1)
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
->
1 2 3    7 4 1
4 5 6 -> 8 5 2
7 8 9    9 6 3
(2)
Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
(3)
Input: matrix = [[1, 1, 2], [5, 3, 1], [5, 3, 5]]
Output:
[[5, 5, 1], [3, 3, 1], [5, 1, 2]]

Constraints:
n == matrix.length.
n == matrix[i].length.
1 <= n <= 100.
-10^4 <= matrix[i][j] <= 10^4


*/

void rotateMatrixBruteForce(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    // take ans[][] matrix of size n.
    vector<vector<int>> temp(n, vector<int>(n));
    // push elements to temp at the indexes they have to be after rotation.
    // formula: matrix[i][j] = temp[j][n-i-1]
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }
    // storing temp[][] matrix values back to original matrix.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}
// TC: O(N^2)
// SC: O(N^2) -> by temp array.

int main()
{
    int n;
    cout << "Enter size of 2D matrix of N*N size: " << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter elements in the 2D matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix before rotation is: " << endl;
    for(auto i : matrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    rotateMatrixBruteForce(matrix);
    cout << "The matrix after rotation by 90 degree clockwise is: " << endl;
    for(auto i : matrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    
    return 0;
}