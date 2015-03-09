/*
Description

In this problem, you have to analyze a particular sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence 
9 1 0 5 4 ,

Ultra-QuickSort produces the output 
0 1 4 5 9 .

Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence.
Input

The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ¡Ü a[i] ¡Ü 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.
Output

For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.
Sample Input

5
9
1
0
5
4
3
1
2
3
0
Sample Output

6
0
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Node
{
	int	pos;
	ll	value;
};
const int	max_n = 500000+1;
int			bit[max_n];
Node		nodes[max_n];
int			a[max_n];
int			n;


bool compare(const Node&a, const Node&b)
{
	return a.value < b.value;
}

void init()
{
	memset(bit, 0, sizeof(bit));
}
void add(int k, ll x)
{
	while (k<=n) {
		bit[k] += x;
		k += k&(-k);
	}
}

ll sum(int k)
{
	ll ans = 0;
	while (k > 0) {
		ans += bit[k];
		k -= k&(-k);
	}
	return ans;
}

void compress()
{
	sort(nodes, nodes+n, compare);
	for (int i=0; i<n; i++)
		a[nodes[i].pos] = i+1;
}

int main()
{
	for(;;) {
		scanf("%d", &n);
		if (n == 0) break;
		ll ans = 0;
		for (int i=0; i<n; i++) {
			scanf("%lld", &nodes[i].value);
			nodes[i].pos = i;
		}
		init();
		compress();
		for (int i=0; i<n; i++) {
			ans += i-sum(a[i]-1);
			add(a[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}