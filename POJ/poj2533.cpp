/*
Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
Sample Input

7
1 7 3 5 9 4 8
Sample Output

4
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector<int>     v;
vector<int>     dp;
int main()
{
    int n;
    scanf("%d", &n);
    v.resize(n);
    dp.resize(n+1, INT_MAX);
    for (int i=0; i<n; i++)
        scanf("%d", &v[i]);
    dp[0] = -1;
    for (int i=0; i<n; i++)
        *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
    for (int i=n; i>=0; i--)
        if (dp[i] != INT_MAX) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}