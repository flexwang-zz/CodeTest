/*
 It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.
 For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.
 Input
 Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.
 Output
 For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
 Sample Input
 3 2 3
 1 2
 1 3
 1 2 3

 Sample Output
 1
 0
 0
 */
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<bool>& used, vector<vector<int>>&g)
{
	used[v] = true;
	for (auto t : g[v])
		if (!used[t]) dfs(t, used, g);
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	for (int i=0; i<k; ++i) {
		int t;
		cin >> t;
		vector<bool> used(n);
		used[t-1] = true;
		int cnt = 0;
		for (int j=0; j<n; ++j)
			if (!used[j]) ++cnt, dfs(j, used, g);
		cout << cnt-1 << endl;
	}
	return 0;
}
