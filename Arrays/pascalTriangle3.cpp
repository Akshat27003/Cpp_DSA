#include<bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.



In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
(1)
Input: n = 4
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]
Explanation: The Pascal's Triangle is as follows:
1
1 1
1 2 1
1 3 3 1
1st Row has its value set to 1.
All other cells take their value as the sum of the values directly above them
(2)
Input: n = 5
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
Explanation: The Pascal's Triangle is as follows:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1st Row has its value set to 1.
All other cells take their value as the sum of the values directly above them
(3)
Input: n = 3
Output:
[[1], [1, 1], [1, 2, 1]]

Constraints:
1 <= n <= 30
All values will fit inside a 32-bit integer


*/

vector<int> generateRow (int n)
{
    vector<int> rth_row;
    rth_row.push_back(1);
    long long ans = 1;
    for(int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        rth_row.push_back(ans); // answer is typecast to int from long.
    }
    return rth_row;
}

vector<vector<int>> pascalTriangle(int r)
{
    vector<vector<int>> answer;
    for(int i = 1; i <= r; i++)
    {
        vector<int> temp = generateRow(i);
        answer.push_back(temp);
    }
    return answer;
}
// TC: O(N^2)
// SC: O(N^2)

int main()
{
    int r;
    cout << "Enter number of rows upto which to print PASCAL'S TRIANGLE:" << endl;
    cin >> r;
    vector<vector<int>> answer = pascalTriangle(r);
    cout << "The corresponding PASCAL'S TRIANGLE is: " << endl;
    for(auto i : answer)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0; 
}