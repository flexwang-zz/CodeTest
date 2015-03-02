/*
Description

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome. 

As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome. 
Input

Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.
Output

Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.
Sample Input

5
Ab3bd
Sample Output

2
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int   max_n = 5001;
int         n;
char        a[max_n];
int         dp[2][max_n];

int main()
{
    scanf("%d%s", &n, a);
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i-1] == a[n-1-(j-1)])
                dp[i&1][j] = dp[(i-1)&1][j-1] + 1;
            else
                dp[i&1][j] = max(dp[(i-1)&1][j], dp[i&1][j-1]);
    printf("%d\n", n-dp[n&1][n]);
    return 0;
}