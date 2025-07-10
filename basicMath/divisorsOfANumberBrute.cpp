#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer n. You need to find all the divisors of n. 
Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.

Examples: (1)
Input: n = 6
Output = [1, 2, 3, 6]
Explanation: The divisors of 6 are 1, 2, 3, 6.

(2)
Input: n = 8
Output: [1, 2, 4, 8]
Explanation: The divisors of 8 are 1, 2, 4, 8.
*/


// Brute Approach.
vector<int> getAllDivisors(int num)
{
    vector<int> answer;
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            answer.push_back(i);
        }
    }
    return answer;
}
// TC: O(N)
// SC: O(sqrt(N)) -> a number N can have at max 2*sqrt(N) divisors.

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    vector<int> divisors = getAllDivisors(n);
    for(auto i : divisors)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}