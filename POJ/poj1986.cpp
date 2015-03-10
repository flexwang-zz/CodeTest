/*
Description

Farmer John's cows refused to run in his marathon since he chose a path much too long for their leisurely lifestyle. He therefore wants to find a path of a more reasonable length. The input to this problem consists of the same input as in "Navigation Nightmare",followed by a line containing a single integer K, followed by K "distance queries". Each distance query is a line of input containing two integers, giving the numbers of two farms between which FJ is interested in computing distance (measured in the length of the roads along the path between the two farms). Please answer FJ's distance queries as quickly as possible! 
Input

* Lines 1..1+M: Same format as "Navigation Nightmare" 

* Line 2+M: A single integer, K. 1 <= K <= 10,000 

* Lines 3+M..2+M+K: Each line corresponds to a distance query and contains the indices of two farms. 
Output

* Lines 1..K: For each distance query, output on a single line an integer giving the appropriate distance. 
Sample Input

7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6
1 4
2 6
Sample Output

13
3
36
Hint

Farms 2 and 6 are 20+3+13=36 apart. 
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> Q;
typedef pair<int, int> E;

const int		max_v = 40000;
const int		max_k = 10002;
vector<E>		G[max_v];
int				depth[max_v], p[max_v];
vector<Q>		q[max_v];
int				ans[max_k];
int				nv, ne, nq;
void init()
{
	memset(p, -1, sizeof(p));
}

inline void add_edge(int s, int t, int d)
{
	G[s].push_back(make_pair(t, d));
	G[t].push_back(make_pair(s, d));
}

void add_query(int s, int t, int pos)
{
	q[s].push_back(make_pair(t, pos));
	q[t].push_back(make_pair(s, pos));
}

void make_set(int i)
{
	p[i] = i;
}

int find(int i)
{
	if (i!=p[i]) p[i] = find(p[i]);
	return p[i];
}

void merge(int i, int j)
{
	i = find(i);
	j = find(j);
	p[j] = i;
}

void dfs(int s, int d)
{
	make_set(s);
	depth[s] = d;
	for (int i=0; i<G[s].size(); i++) {
		E& e = G[s][i];
		if (p[e.first] < 0) {
			dfs(e.first, depth[s] + e.second);
			merge(s, e.first);
		}
	}
	for (int i=0; i<q[s].size(); i++) {
		int v = q[s][i].first;
		int pos =  q[s][i].second;
		if (p[v] >= 0) {
			ans[pos] = depth[s]+depth[v]-2*depth[find(v)];
		}
	}
}

int main()
{
	scanf("%d%d", &nv, &ne);
	init();
	char ss[3];
	for (int i=0; i<ne; i++) {
		int s, t, d;
		
		scanf("%d%d%d%s", &s, &t, &d, ss);
		add_edge(s-1, t-1, d);
	}
	scanf("%d", &nq);
	for (int i=0; i<nq; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		add_query(s-1, t-1, i);
	}
	dfs(0, 0);
	for (int i=0; i<nq; i++) {
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
