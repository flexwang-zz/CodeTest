//#define POJ_1185
#ifdef  POJ_1185
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int	max_n = 10;
const int	max_m = 101;
vector<int>	possible;
int			S;
int			n, m;
int			no[max_m], dp[2][1<<(max_n*2)];
//int			state[1<<(2*max_n)], tmp[1<<(2*max_n)], sp, sp2;
int			state[3000], tmp[3000], sp, sp2;
bool		tab[1<<(2*max_n)];

bool	valid(int x)
{
	if ((x&(x<<1)) || (x&(x<<2)))	return false;
	return true;
}

void	init_possible()
{
	S = 1 << m;
	for (int s=0; s<S; s++)
		if (valid(s)) possible.push_back(s);
}

int		count(int x)
{
	int ans = 0;
	while (x > 0) {
		ans ++;
		x -= x&(-x);
	}
	return ans;
}

void	init_tab()
{
	memset(tab, 0, sizeof(tab));
	sp2 = 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		char str[max_n];
		scanf("%s", str);
		for (int j=0; j<m; j++) 
			if (str[j] == 'H')
				no[i] += 1<<j;
	}
	memset(dp, -1, sizeof(dp));
	init_possible();
	init_tab();
	for (int p=0; p<possible.size(); p++) {
		int s = possible[p];
		if (s&no[0]) continue;
		int st = s << m;
		dp[0&1][st] = count(s);
		if (!tab[st]) {
			tab[st] = true;
			state[sp++] = st;
		}
	}
	for (int i=1; i<n; i++) {
		init_tab();
		for (int p=0; p<possible.size(); p++) {
			int s = possible[p];
			int cnt = count(s);
			if (s&no[i]) continue;
			for (int p2=0; p2<sp; p2++) {
				int s2 = state[p2];
				if ((s&s2)!=0 || (s&(s2>>m))!=0 ) continue;
				
				int st = (s2>>m)|(s<<m);
				dp[i&1][st] = max(dp[i&1][st], cnt+dp[(i-1)&1][s2]);
				if (!tab[st]) {
					tab[st] = true;
					tmp[sp2++] = st;
				}
			}
		}
		memcpy(state, tmp, sizeof(tmp));
		sp = sp2;
	}
	int ans = 0;
	for (int p2=0; p2<sp; p2++) {
		int s = state[p2];
		ans = max(ans, dp[(n-1)&1][s]);
	}
	printf("%d\n", ans);
	return 0;	 
}


#endif