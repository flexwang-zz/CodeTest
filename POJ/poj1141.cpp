/*
Description

Let us define a regular brackets sequence in the following way: 

1. Empty sequence is a regular sequence. 
2. If S is a regular sequence, then (S) and [S] are both regular sequences. 
3. If A and B are regular sequences, then AB is a regular sequence. 

For example, all of the following sequences of characters are regular brackets sequences: 

(), [], (()), ([]), ()[], ()[()] 

And all of the following character sequences are not: 

(, [, ), )(, ([)], ([(] 

Some sequence of characters '(', ')', '[', and ']' is given. You are to find the shortest possible regular brackets sequence, that contains the given character sequence as a subsequence. Here, a string a1 a2 ... an is called a subsequence of the string b1 b2 ... bm, if there exist such indices 1 = i1 < i2 < ... < in = m, that aj = bij for all 1 = j = n.
Input

The input file contains at most 100 brackets (characters '(', ')', '[' and ']') that are situated on a single line without any other characters among them.
Output

Write to the output file a single line that contains some regular brackets sequence that has the minimal possible length and contains the given sequence as a subsequence.
Sample Input

([(]
Sample Output

()[()]
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;

const int	max_n = 105;
char		s[max_n];
int			n;
int			dp[max_n][max_n];
int			pre[max_n][max_n];
bool mat(char a, char b)
{
	if (a=='('&&b==')' || a=='['&&b==']')
		return true;
	return false;
}

void print(int a, int b)
{
	if (a > b)	return;
	if (a==b) {
		if (s[a] == '(' || s[a] == ')')
			printf("()");
		else
			printf("[]");
	}
	else if (pre[a][b] < 0) {
		printf("%c", s[a]);
		print(a+1, b-1);
		printf("%c", s[b]);
	}
	else {
		print(a, pre[a][b]);
		print(pre[a][b]+1, b);
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i=0; i<n; i++)
		dp[i][i] = 1;
	for (int i=2; i<=n; i++)
		for (int j=0; j<=n-i; j++) {
			dp[j][j+i-1] = INT_MAX;
			if (mat(s[j], s[j+i-1])) {
				dp[j][j+i-1] = dp[j+1][j+i-2];
				pre[j][j+i-1] = -1;
			}
			for (int k=j; k<j+i-1; k++) {
				if (dp[j][k] + dp[k+1][j+i-1] < dp[j][j+i-1]) {
					dp[j][j+i-1] = dp[j][k] + dp[k+1][j+i-1];
					pre[j][j+i-1] = k;
				}
			}
			
		}

	print(0, n-1);
	printf("\n");
	return 0;
}