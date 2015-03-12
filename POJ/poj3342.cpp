/*
Description

Dear Contestant,

I'm going to have a party at my villa at Hali-Bula to celebrate my retirement from BCM. I wish I could invite all my co-workers, but imagine how an employee can enjoy a party when he finds his boss among the guests! So, I decide not to invite both an employee and his/her boss. The organizational hierarchy at BCM is such that nobody has more than one boss, and there is one and only one employee with no boss at all (the Big Boss)! Can I ask you to please write a program to determine the maximum number of guests so that no employee is invited when his/her boss is invited too? I've attached the list of employees and the organizational hierarchy of BCM.

Best,
--Brian Bennett

P.S. I would be very grateful if your program can indicate whether the list of people is uniquely determined if I choose to invite the maximum number of guests with that condition.

Input

The input consists of multiple test cases. Each test case is started with a line containing an integer n (1 ¡Ü n ¡Ü 200), the number of BCM employees. The next line contains the name of the Big Boss only. Each of the following n-1 lines contains the name of an employee together with the name of his/her boss. All names are strings of at least one and at most 100 letters and are separated by blanks. The last line of each test case contains a single 0.

Output

For each test case, write a single line containing a number indicating the maximum number of guests that can be invited according to the required condition, and a word Yes or No, depending on whether the list of guests is unique in that case.

Sample Input

6
Jason
Jack Jason
Joe Jack
Jill Jason
John Jack
Jim Jill
2
Ming
Cho Ming
0
Sample Output

4 Yes
1 No
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int			max_n = 205;
map<string, int>	m;
vector<int>			G[max_n];
int					dp[max_n][2];
bool				u[max_n][2];
int					n, cnt;
void	init()
{
	m.clear();
	memset(dp, 0, sizeof(dp));
	memset(u, true, sizeof(u));
	for (int i=0; i<max_n; i++)
		G[i].clear();
	cnt = 0;
}

int		add_str(string&s)
{
	int ans;
	if (m.find(s) == m.end()) {
		ans = cnt;
		m[s] = cnt++;
	}
	else
		ans = m[s];
	return ans;
}

void	dfs(int s) {
	for (int i=0; i<G[s].size(); i++) {
		int v = G[s][i];
		dfs(v);
		dp[s][1] += dp[v][0];
		u[s][1] &= u[v][0];
		if (dp[v][0] > dp[v][1]) {
			dp[s][0] += dp[v][0];
			u[s][0] &= u[v][0];
		}
		else if (dp[v][0] < dp[v][1]) {
			dp[s][0] += dp[v][1];
			u[s][0] &= u[v][1];
		}
		else {
			dp[s][0] += dp[v][1];
			u[s][0] = false;
		}
	}
}
int main()
{
	for(;;) {
		cin >> n;
		if (n ==0) break;
		init();
		string root;
		cin >> root;
		add_str(root);
		dp[0][1] = 1;
		for (int i=1; i<n; i++) {
			string a, b;
			cin >> a >> b;
			int aa = add_str(a);
			int bb = add_str(b);
			G[bb].push_back(aa);
			dp[aa][1] = 1;
		}
		dfs(0);
		int ans;
		bool flag;
		if (dp[0][0] > dp[0][1]) {
			ans = dp[0][0];
			flag = u[0][0];
		}
		else if (dp[0][1] > dp[0][0]) {
			ans = dp[0][1];
			flag = u[0][1];
		}
		else {
			ans = dp[0][1];
			flag =  false;
		}
		printf("%d %s\n", ans, flag?"Yes":"No");
	}
	return 0;
}