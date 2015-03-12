/*
Description

Farmer John has noticed that the quality of milk given by his cows varies from day to day. On further investigation, he discovered that although he can't predict the quality of milk from one day to the next, there are some regular patterns in the daily milk quality.

To perform a rigorous study, he has invented a complex classification scheme by which each milk sample is recorded as an integer between 0 and 1,000,000 inclusive, and has recorded data from a single cow over N (1 ¡Ü N ¡Ü 20,000) days. He wishes to find the longest pattern of samples which repeats identically at least K (2 ¡Ü K ¡Ü N) times. This may include overlapping patterns -- 1 2 3 2 3 2 3 1 repeats 2 3 2 3 twice, for example.

Help Farmer John by finding the longest repeating subsequence in the sequence of samples. It is guaranteed that at least one subsequence is repeated at least K times.

Input

Line 1: Two space-separated integers: N and K 
Lines 2..N+1: N integers, one per line, the quality of the milk on day i appears on the ith line.
Output

Line 1: One integer, the length of the longest pattern which occurs at least K times
Sample Input

8 2
1
2
3
2
3
2
3
1
Sample Output

4
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int	max_n = 20005;
int			n, K;
int			a[max_n], sa[max_n], tmp[max_n], rank[max_n], lcp[max_n];
int			k;

bool	compare(int i, int j)
{
	if (rank[i] != rank[j])	return rank[i] <rank[j];
	int ri = i+k <=n?rank[i+k]:-1;
	int rj = j+k <=n?rank[j+k]:-1;
	return ri < rj;
}
void	compute_sa()
{
	for (int i=0; i<=n; i++) {
		sa[i] = i;
		rank[i] = i<n?a[i]:-1;
	}
	for (k=1; k<=n; k *= 2) {
		std::sort(sa, sa+n+1, compare);
		tmp[sa[0]] = 0;
		for (int i=1; i<=n; i++)
			tmp[sa[i]] = compare(sa[i-1], sa[i])?tmp[sa[i-1]]+1:tmp[sa[i-1]];
		for (int i=0; i<=n; i++)
			rank[i] = tmp[i];
		//memcpy(rank, tmp, sizeof(rank));
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
		for (;i+h<n&&j+h<n; h++)
			if (a[j+h] != a[i+h]) break;
		lcp[rank[i]-1] = h;
	}
}

bool	check(int len)
{
	int sum = 1;
	for (int i=0; i<n; i++) {
		if (lcp[i] < len)
			sum = 1;
		else {
			sum ++;
			if (sum >= K)	return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d", &n, &K);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	compute_sa();
	compute_lcp();
	int l = 1;
	int r = n+1;
	while (l+1 < r) {
		int m = (l+r)/2;
		if (check(m)) l = m;
		else r = m;
	}
	printf("%d\n", l);
	return 0;
}