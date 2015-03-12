/*
Description

Bob enjoys playing computer games, especially strategic games, but sometimes he cannot find the solution fast enough and then he is very sad. Now he has the following problem. He must defend a medieval city, the roads of which form a tree. He has to put the minimum number of soldiers on the nodes so that they can observe all the edges. Can you help him? 

Your program should find the minimum number of soldiers that Bob has to put for a given tree. 

For example for the tree: 


the solution is one soldier ( at the node 1).
Input

The input contains several data sets in text format. Each data set represents a tree with the following description: 

the number of nodes 
the description of each node in the following format 
node_identifier:(number_of_roads) node_identifier1 node_identifier2 ... node_identifiernumber_of_roads 
or 
node_identifier:(0) 

The node identifiers are integer numbers between 0 and n-1, for n nodes (0 < n <= 1500);the number_of_roads in each line of input will no more than 10. Every edge appears only once in the input data.
Output

The output should be printed on the standard output. For each given input data set, print one integer number in a single line that gives the result (the minimum number of soldiers). An example is given in the following:
Sample Input

4
0:(1) 1
1:(2) 2 3
2:(0)
3:(0)
5
3:(3) 1 4 2
1:(1) 0
2:(0)
0:(0)
4:(0)
Sample Output

1
2
*/
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int	max_n = 2000;
vector<int>	G[max_n];
int			n;
int			dp[max_n][2];
bool		used[max_n];
void	init()
{
	for (int i=0; i<max_n; i++)
		G[i].clear();
	memset(used, 0, sizeof(used));
	memset(dp, 0, sizeof(dp));
}
void	add_edge(int s, int t)
{
	G[s].push_back(t);
	G[t].push_back(s);
}

void	dfs(int s)
{
	used[s] = true;
	for (int i=0; i<G[s].size(); i++) {
		int v  = G[s][i];
		if (used[v]) continue;
		dfs(v);
		dp[s][0] += dp[v][1];
		dp[s][1] += min(dp[v][0], dp[v][1]);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)  {
		init();
		for (int i=0; i<n; i++) {
			dp[i][1] = 1;
			int j, k;
			scanf("%d:(%d)", &j, &k);
			for (int l=0; l<k; l++) {
				int m;
				scanf("%d", &m);
				add_edge(j, m);
			}
		}
		dfs(0);
		printf("%d\n", min(dp[0][0], dp[0][1]));

	}
	return 0;
}