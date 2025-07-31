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

void rotateMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    // transpose.. we need to do for only 1 half of the matrix separated by the diagonal.
    // transposing is cols in rows and rows in col.
    // TC: O(N*2) * O(N*2)
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = (i + 1); j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each row.
    // TC: O(N * N/2).
    for(int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end()); 
    }
}
// TC: O(N^2).
// SC: O(1) -> done in place.

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

    rotateMatrix(matrix);
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