#include <stdio.h>
#include <string.h>
#include <algorithm>
const int	max_n = 1000001;
char		s[max_n];
int			rank[max_n], sa[max_n], lcp[max_n], tmp[max_n], k;
int			n;
bool	compare(int i, int j)
{
	if (rank[i] != rank[j])	return rank[i] < rank[j];
	int ri = (i+k)<=n?rank[i+k]:-1;
	int rj = (j+k)<=n?rank[j+k]:-1;
	return ri < rj;
}

void	compute_sa()
{
	for (int i=0; i<=n; i++) {
		sa[i] = i;
		rank[i] = i<n?s[i]:-1;
	}
	for (k=1; k<=n; k*=2) {
		std::sort(sa, sa+n+1, compare);
		tmp[sa[0]] = 0;
		for (int i=1; i<=n; i++)
			tmp[sa[i]] = tmp[sa[i-1]] + (compare(sa[i-1], sa[i])?1:0);
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
	for (int i=0; i<n; i++) {
		int j = sa[rank[i]-1];
		if (h>0) h--;
		for (;j+h<n&&i+h<n; h++)
			if (s[j+h] != s[i+h])
				break;
		lcp[rank[i]-1] = h;
	}
}

bool solve()
{
	scanf("%s", s);
	if (s[0] == '.') return false;
	n = strlen(s);
	if (n==1) {
		printf("1\n");
		return true;
	}
	compute_sa();

	//compute_lcp();
	int t;
	for (t=0; t<=n; t++) {
		if (sa[t] == 0)
			break;
	}
	int dx = sa[t-1];
	if (n%dx)
		printf("1\n");
	else {
		if (sa[t-(n/dx-1)]+dx == n)
			printf("%d\n", n/dx);
		else
			printf("1\n");
	}
	return true;
}

int main()
{
	while(solve());
	return 0;
}