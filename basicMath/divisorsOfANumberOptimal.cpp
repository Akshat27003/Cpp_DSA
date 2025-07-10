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

// Optimal Approach:
// use property of divison and divisors which says that.
// divisors of a number appear in pairs.
// if d is a divisor of n, n/d will also be a divisor of n.
// d and n/d can be same. we need to check it ourselves.
// this property is symmetric around sqrt(N) as
// the smaller divisor of the pair will alway be
// less than or equal (<=) to sqrt(n).
vector<int> getAllDivisors(int num)
{
    vector<int> answer;
    for(int i = 1; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            answer.push_back(i);
            //checking for counterpart divisor of i.
            if(i != (num / i))
            {
                answer.push_back(num/i);
            }
        }

    }
    sort(answer.begin(), answer.end());
    return answer;
}
//TC:O(sqrt(N)) + O(K*log(K)) 
// K*log(K) is the Time Complexity for the sort algorithm.
// O(sqrt(N)) is the Time Complexity pertaining to the loop.
//SC: O(sqrt(N)) -> a number N can have at max 2*sqrt(N) divisors.

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