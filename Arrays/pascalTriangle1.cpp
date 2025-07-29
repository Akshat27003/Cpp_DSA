#include<bits/stdc++.h>
using namespace std;

/*
Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.



In Pascal's triangle:

The first row contains a single element 1.
Each row has one more element than the previous row.
Every row starts and ends with 1.


For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum 
of the two elements directly above it from the previous row:

Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
where indexing is 1-based

Examples:
(1)
Input: r = 4, c = 2
Output: 3
Explanation: The Pascal's Triangle is as follows:
1
1 1
1 2 1
1 3 3 1
....
Thus, value at row 4 and column 2 = 3
(2)
Input: r = 5, c = 3
Output: 6
Explanation: The Pascal's Triangle is as follows:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
....
Thus, value at row 5 and column 3 = 6
(3)
Input: r = 6, c = 2
Output:
5

Constraints:
1 <= r, c <= 30
c <= r
All values will fit inside a 32-bit integer.


*/

int nCr(int n, int r)
{
    int mini = min(r, (n - r));
    int result = 1;
    for(int i = 0; i < mini; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

int pascalTriangle(int r, int c)
{
    return nCr((r - 1), (c - 1));
}
// TC: O(c) -> col no.
// SC: O(1)

int main()
{
    int r, c;
    cout << "Enter row number and col number for the pascal triangle: " << endl;
    cin >> r;
    cin >> c;
    int answer = pascalTriangle(r, c);
    cout << "The value at " << r << "th row and " << c << "th col is: " << answer << endl;
    return 0; 
}