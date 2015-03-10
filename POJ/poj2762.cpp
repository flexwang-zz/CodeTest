/*
Description

In order to make their sons brave, Jiajia and Wind take them to a big cave. The cave has n rooms, and one-way corridors connecting some rooms. Each time, Wind choose two rooms x and y, and ask one of their little sons go from one to the other. The son can either go from x to y, or from y to x. Wind promised that her tasks are all possible, but she actually doesn't know how to decide if a task is possible. To make her life easier, Jiajia decided to choose a cave in which every pair of rooms is a possible task. Given a cave, can you tell Jiajia whether Wind can randomly choose two rooms without worrying about anything?
Input

The first line contains a single integer T, the number of test cases. And followed T cases. 

The first line for each case contains two integers n, m(0 < n < 1001,m < 6000), the number of rooms and corridors in the cave. The next m lines each contains two integers u and v, indicating that there is a corridor connecting room u and room v directly. 
Output

The output should contain T lines. Write 'Yes' if the cave has the property stated above, or 'No' otherwise.
Sample Input

1
3 3
1 2
2 3
3 1
Sample Output

Yes
*/
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int	max_n = 1001;
int			nv, ne;
vector<int>	G[max_n], rG[max_n], G2[max_n];
bool		used[max_n];
vector<int>	vs;
int			comp[max_n];
int			in[max_n];
void init()
{
	for (int i=0; i<max_n; i++) {
		G[i].clear();
		rG[i].clear();
		G2[i].clear();
	}
	memset(comp, -1, sizeof(comp));
	memset(in, 0, sizeof(in));
}

void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int s)
{
	used[s] = true;
	for (int i=0; i<G[s].size(); i++) {
		if (!used[G[s][i]]) dfs(G[s][i]);
	}
	vs.push_back(s);
}
int dfs2(int s)
{
	used[s] = true;
	for (int i=0; i<G2[s].size(); i++) {
		if (!used[G2[s][i]]) return dfs2(G2[s][i])+1;
	}
	return 1;
}
void rdfs(int s, int k)
{
	used[s] = true;
	comp[s] = k;
	for (int i=0; i<rG[s].size(); i++)
		if (!used[rG[s][i]]) rdfs(rG[s][i], k);
}
int scc()
{
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int i=0; i<nv; i++)
		if (!used[i]) dfs(i);
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i=vs.size()-1; i>=0; i--) 
		if (!used[vs[i]]) 
			rdfs(vs[i], k++);
		
	return k;
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--) {
		init();
		scanf("%d%d", &nv, &ne);
		for (int i=0; i<ne; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			add_edge(x-1, y-1);
		}
		int k = scc();
		for (int i=0; i<nv; i++)
			for (int j=0; j<G[i].size(); j++)
				if (comp[i] != comp[G[i][j]]) {
					in[comp[G[i][j]]]++;
					G2[comp[i]].push_back(comp[G[i][j]]);
				}
		memset(used, 0, sizeof(used));
		bool flag = true;
		for (int i=0; i<k; i++)
			if (in[i] == 0) {
				flag = dfs2(i)==k;
				break;
			}
		printf("%s\n", flag?"Yes":"No");
	}
	return 0;
}