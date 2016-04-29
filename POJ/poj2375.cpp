#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int	max_n = 500*500;
vector<int>	G[max_n], rG[max_n];
int			gSize[max_n], rgSize[max_n];
bool		used[max_n];
int			vs[max_n];
int			vs_size = 0;
int			w, h;
int			x[500][500];
int			nv;
int			comp[max_n], out[max_n], in[max_n];
void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}
int toindex(int xx, int yy)
{
	return xx*w+yy;
}
void dfs(int s)
{
	used[s] = true;
	for (int i=0; i<G[s].size(); i++)
		if (!used[G[s][i]])
			dfs(G[s][i]);
	vs[vs_size++] = s;
}

void rdfs(int s, int k)
{
	used[s] = true;
	comp[s] = k;
	for (int i=0; i<rG[s].size(); i++)
		if (!used[rG[s][i]])
			rdfs(rG[s][i], k);
}

int scc()
{
	memset(used, false, sizeof(used));
	for (int i=0; i<nv; i++)
		if (!used[i])
			dfs(i);
	memset(used, false, sizeof(used));
	int k = 0;
	memset(comp, -1, sizeof(comp));
	for (int i=vs_size-1; i>=0; i--)
		if (!used[vs[i]]) 
			rdfs(vs[i], k++);
		
	return k;
}

int main()
{
	scanf("%d%d", &w, &h);
	nv = w*h;
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			scanf("%d", &x[i][j]);
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++) {
			if (i>0 && x[i][j] >= x[i-1][j])
				add_edge(toindex(i, j), toindex(i-1, j));
			if (i < h-1 && x[i][j] >= x[i+1][j])
				add_edge(toindex(i, j), toindex(i+1, j));
			if (j>0 && x[i][j] >= x[i][j-1])
				add_edge(toindex(i, j), toindex(i, j-1));
			if (j < w-1 && x[i][j] >= x[i][j+1])
				add_edge(toindex(i, j), toindex(i, j+1));
		}

	int k = scc();
	if (k == 1) 
		printf("0\n");
	else {
		for (int i=0; i<nv; i++)
			for (int j=0; j<G[i].size(); j++) 
				if (comp[i] != comp[G[i][j]]) {
					out[comp[i]] ++;
					in[comp[G[i][j]]] ++;
				}
		int a = 0, b = 0;
		for (int i=0; i<k; i++) {
			a += out[i] == 0?1:0;
			b += in[i] == 0?1:0;
		}
		printf("%d\n", max(a, b));
	}
	return 0;
}