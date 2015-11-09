//#define POJ_3254
#ifdef  POJ_3254
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
const int	mod = 100000000;
const int	max_n = 13;
vector<int>	possible;
int			no[max_n];
ll			dp[max_n][1<<max_n];
int			m, n;
int			S;
void init_possible()
{
	S = (1<<n);
	for (int s=0; s<S; s++)
		if ((s&(s<<1)) == 0) possible.push_back(s);
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			int b;
			scanf("%d", &b);
			if (b == 0)
				no[i] += 1<<j;
		}
	}
	
	init_possible();
	for (int p=0; p<possible.size(); p++) {
		int s = possible[p];
		if ((s&no[0]) == 0) 
			dp[0][s] = 1;
	}
	for (int i=1; i<m; i++) {
		for (int p=0; p<possible.size(); p++) {
			int s = possible[p];
			if (s&no[i]) continue;
			for (int p2=0; p2<possible.size(); p2++) {
				int s2 = possible[p2];
				if (s2&no[i-1]) continue;
				if (s&s2) continue;
				dp[i][s] = (dp[i][s]+dp[i-1][s2])%mod;
			}
		}
	}
	ll ans = 0;
	for (int p=0; p<possible.size(); p++) {
		int s = possible[p];
		ans = (ans + dp[m-1][s])%mod;
	}
	printf("%lld", ans);
	return 0;
}

#endif