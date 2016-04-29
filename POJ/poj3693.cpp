#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;
const int	max_n = 100001;
char		s[max_n];
int			sa[max_n], rank[max_n], tmp[max_n], lcp[max_n], k;
int			n;

bool	compair(int i, int j)
{
	if (rank[i] != rank[j])	return rank[i] < rank[j];
	int ri = i+k<=n?rank[i+k]:-1;
	int rj = j+k<=n?rank[j+k]:-1;
	return ri < rj;
}

void	compute_sa()
{
	for (int i=0; i<=n; i++) {
		sa[i] = i;
		rank[i] = i<n?s[i]:-1;
	}
	for (k=1; k<=n; k*=2) {
		sort(sa, sa+n+1, compair);
		tmp[sa[0]] = 0;
		for (int i=0; i<=n; i++) 
			tmp[sa[i]] = compair(sa[i-1], sa[i])?(tmp[sa[i-1]]+1):tmp[sa[i-1]];
		for (int i=0; i<=n; i++)
			rank[i] = tmp[i];
	}
}

void	compute_lcp()
{
	for (int i=0; i<=n; i++)
		rank[sa[i]] = i;
	int h = 0;
	lcp[0] = 0;
	for (int i=1; i<=n; i++) {
		int j = sa[rank[i]-1];
		if (h > 0) h--;
		for (;h+j<n&&h+i<n; h++)
			if (s[h+j] != s[h+i])
				break;
		lcp[rank[i]-1] = h;
	}
}

void solve()
{
	compute_sa();
	compute_lcp();

}

int main()
{
	for (;;) {
		scanf("%s", s);
		n = strlen(s);
		if (s[0] == '#')
			break;
		solve();
	}
}