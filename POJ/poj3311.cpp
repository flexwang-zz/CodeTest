/*
Description

The Pizazz Pizzeria prides itself in delivering pizzas to its customers as fast as possible. Unfortunately, due to cutbacks, they can afford to hire only one driver to do the deliveries. He will wait for 1 or more (up to 10) orders to be processed before he starts any deliveries. Needless to say, he would like to take the shortest route in delivering these goodies and returning to the pizzeria, even if it means passing the same location(s) or the pizzeria more than once on the way. He has commissioned you to write a program to help him.

Input

Input will consist of multiple test cases. The first line will contain a single integer n indicating the number of orders to deliver, where 1 ¡Ü n ¡Ü 10. After this will be n + 1 lines each containing n + 1 integers indicating the times to travel between the pizzeria (numbered 0) and the n locations (numbers 1 to n). The jth value on the ith line indicates the time to go directly from location i to location j without visiting any other locations along the way. Note that there may be quicker ways to go from i to j via other locations, due to different speed limits, traffic lights, etc. Also, the time values may not be symmetric, i.e., the time to go directly from location i to j may not be the same as the time to go directly from location j to i. An input value of n = 0 will terminate input.

Output

For each test case, you should output a single number indicating the minimum time to deliver all of the pizzas and return to the pizzeria.

Sample Input

3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
Sample Output

8
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int	max_n = 11;
const int	inf = 1<<30;
int			d[max_n][max_n];
int			dp[1<<max_n][max_n];
int			n, S;

void init()
{
	for (int i=0; i<max_n; i++)
		for (int j=0; j<max_n; j++)
			d[i][j] = inf;
	for (int i=0; i<(1<<max_n); i++)
		for (int j=0; j<max_n; j++)
			dp[i][j] = inf;
}
int main()
{
	init();
	for (;;) {
		scanf("%d", &n);
		if (!n)	break;
		init();
		n++;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%d", &d[i][j]);
		for (int k=0; k<n; k++)
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		S = 1 << n;
		dp[S-1][0] = 0;
		for (int s=S-2; s>=0; s--)
			for (int v=0; v<n; v++)
				for (int u=0; u<n; u++)
					dp[s][v] = min(dp[s][v], dp[s|(1<<u)][u] + d[u][v]);
		printf("%d\n", dp[0][0]);
	}
	return 0;
}