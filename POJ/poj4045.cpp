/*
Description
 

The massive tsunami that struck the coastal city has  washed away many of 
inhabitants and facilities there. After the tsunami,  the power supply facilities  of  the 
coastal city  are completely destroyed. People are in panic in the dark night. Doubts 
remain over whether the communities will be able to rebuild the city. To calm people 
down, the heads of the city are planning to rebuild  the city to start with the recovery 
of the power supply facilities. 
The coastal city consists of n communities which are numbered from 1 to n. To 
save the electric cables,  n-1  cables has been used to connect these  communities 
together, so that each pair of communities  is able to transfer electronic energy 
mutually.   
The heads of the city decide to set a power station in one of the communities. 
There  is  thermal energy loss along the cables. Each cable has a resistance of R ohm. 
The total  thermal energy loss is the sum of  I^2*Ri . Here Ri is the total residence along 
the path between the ith community and the power station, and I is a constant. They 
are troubling their head on the issue of where to set the power station to make the total 
thermal energy loss minimized.
Input
 

There are multiple test cases. 
The first line contains one integer indicating the number of test cases. 
For each test case, the first line contains three positive integers  n,  I  and  R, 
indicating  the number of communities, the  above mentioned constant  and the 
residence of each cable. (3 ¡Ü n ¡Ü 50000, 1 ¡Ü I ¡Ü 10, 1 ¡Ü R ¡Ü 50) 
The next n-1 lines, each describe a cable connection by two integers X, Y, which 
indicates that between community X and community Y, there is a cable. 
Output
 

For each test case, please output two lines. 
The first line is the minimum total thermal energy loss. 
The second line is all the optional communities in ascending order. 
You are requested to leave a blank line after each test case. 
Sample Input
2 
5 1 1 
3 2 
1 2 
5 2 
4 3 6 1 2 
1 2 
2 3 
3 4 
2 6 
3 5 
Sample Output
5 
2 
 
14 
2 3
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int	max_n = 50002;
vector<int>	G[max_n];
ll			n, I, R;
ll			d[max_n], cnt[max_n];
vector<int>	ans;
ll			min_cost;
bool		used[max_n];

void add_edge(int s, int t)
{
	G[s].push_back(t);
	G[t].push_back(s);
}
void dfs1(int s)
{
	used[s] = true;
	for (int i=0; i<G[s].size(); i++) {
		int v = G[s][i];
		if (used[v]) continue;
		dfs1(v);
		cnt[s] += cnt[v];
		d[s] += d[v] + cnt[v];
	}
}
void dfs2(int s, ll dist)
{
	used[s] = true;
	ll cost = dist + d[s];
	if (cost < min_cost) {
		min_cost = cost;
		ans.resize(1);
		ans[0] = s;
	}
	else if(cost == min_cost)
		ans.push_back(s);

	for (int i=0; i<G[s].size(); i++) {
		int v = G[s][i];
		if (used[v]) continue;
		dfs2(v, dist+n-cnt[s]+d[s]-d[v]-cnt[v]+cnt[s]-cnt[v]);
	}
}
void init()
{
	for (int i=0; i<max_n; i++)
		G[i].clear();
	for (int i=0; i<n; i++) 
		cnt[i] = 1ll;		
	memset(d, 0, sizeof(d));
	min_cost = INT_MAX;
	ans.clear();
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--) {
		scanf("%d %lld %lld", &n, &I, &R);
		init();
		for (int i=0; i<n-1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			add_edge(a-1, b-1);
		}
		memset(used, 0, sizeof(used));
		dfs1(0);
		memset(used, 0, sizeof(used));
		dfs2(0, 0);
		printf("%lld\n", I*I*R*min_cost);
		sort(ans.begin(), ans.end());
		for (int i=0; i<ans.size(); i++)
			printf("%d%c", ans[i] + 1, i==ans.size()-1?'\n':' ');
		printf("\n");
	}
	return 0;
}