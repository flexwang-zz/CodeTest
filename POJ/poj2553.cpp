/*
Description

We will use the following (standard) definitions from graph theory. Let V be a nonempty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V¡ÁV, its elements being called edges. Then G=(V,E) is called a directed graph. 
Let n be a positive integer, and let p=(e1,...,en) be a sequence of length n of edges ei¡ÊE such that ei=(vi,vi+1) for a sequence of vertices (v1,...,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1¡úvn+1). 
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v¡ÊV|?w¡ÊV:(v¡úw)?(w¡úv)}. You have to calculate the bottom of certain graphs.
Input

The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E), where the vertices will be identified by the integer numbers in the set V={1,...,v}. You may assume that 1<=v<=5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,...,ve,we with the meaning that (vi,wi)¡ÊE. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output

For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line. 
Sample Input

3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output

1 3
2
*/
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int	max_n = 5000;
vector<int>	G[max_n], rG[max_n];
bool		used[max_n];
int			comp[max_n], out[max_n];
int			nv, ne;
vector<int>	vs;
void init()
{
	for (int i=0; i<max_n; i++) {
		G[i].clear();
		rG[i].clear();
	}
	vs.clear();
	memset(comp, -1, sizeof(comp));
	memset(out, 0, sizeof(out));
}

void add_edge(int s, int t)
{
	G[s].push_back(t);
	rG[t].push_back(s);
}

void dfs(int s)
{
	used[s] = true;
	for (int i=0; i<G[s].size(); i++)
		if (!used[G[s][i]])
			dfs(G[s][i]);
	vs.push_back(s);
}

void rdfs(int s, int k)
{
	used[s] = true;
	comp[s] = k;
	for (int i=0; i<rG[s].size(); i++)
		if (!used[rG[s][i]])
			rdfs(rG[s][i], k);
}

int main()
{
	for (;;) {
		init();
		scanf("%d", &nv);
		if (nv == 0) break;
		scanf("%d", &ne);
		for (int i=0; i<ne; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			add_edge(x, y);
		}

		memset(used, false, sizeof(used));
		for (int i=0; i<nv; i++)
			if (!used[i])
				dfs(i);
		memset(used, false, sizeof(used));
		int k = 0;
		for (int i=vs.size()-1; i>=0; i--)
			if (!used[vs[i]])
				rdfs(vs[i], k++);
		for (int i=0; i<nv; i++)
			for (int j=0; j<G[i].size(); j++) {
				if (comp[i] != comp[G[i][j]])
					out[comp[i]]++;
			}
		for (int i=0; i<nv; i++)
			if (out[comp[i]] == 0)
				printf("%d ", i+1);
		printf("\n");
	}
	return 0;
}