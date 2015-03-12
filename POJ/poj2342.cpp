/*
Description

There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.
Input

Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N ¨C 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form: 
L K 
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line 
0 0 
Output

Output should contain the maximal sum of guests' ratings.
Sample Input

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output

5
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int	max_n = 6001;
int			dp[max_n][2];
vector<int>	G[max_n];
int			n;

void	dfs(int s)
{
	for (int i=0; i<G[s].size(); i++) {
		int v = G[s][i];
		dfs(v);
		dp[s][0] += max(dp[v][0], dp[v][1]);
		dp[s][1] += dp[v][0];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &dp[i][1]);
	int root = 0;
	for (;;) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a==0)	break;
		a--; b--;
		G[b].push_back(a);
		root = b;
	}
	dfs(root);
	printf("%d\n", max(dp[root][0], dp[root][1]));
	return 0;
}