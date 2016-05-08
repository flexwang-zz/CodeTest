/*
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=10^5) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	vector<int> table1(n);
	vector<int> table2(n);

	int nswap = 0;
	int nright = 0;
	int zeropos;

	for(int i=0; i<n; i++)
	{
		scanf("%d", &table1[i]);

		table2[table1[i]] = i;

		if( table1[i] == i)
		{
			nright ++;
		}

		if( table1[i] == 0)
		{
			zeropos = i;
		}
	}

	if( nright >= n)
	{
		printf("%d", nswap);
		return 0;
	}

	while( zeropos)
	{
		table1[zeropos] = zeropos;
		table1[table2[zeropos]] = 0;

		table2[0] = table2[zeropos];
		table2[zeropos] = zeropos;

		zeropos = table2[0];

		nright++;
		nswap ++;

		if( zeropos == 0)
		{
			nright++;
		}
	}
	
	
	if( nright >= n)
	{
		printf("%d", nswap);
		return 0;
	}

	for( int i=0; i<n; i++)
	{
		if( table1[i] == i)
		{
			continue;
		}
		
		nswap += 2;

		int head = i;

		while(table1[head] != head)
		{
			int pos = table2[head];
			int tmp = table1[head];
			table1[pos] = table1[head];
			table1[head] = head;

			table2[head] = head;
			table2[tmp] = pos;
			
			head = pos;
			nswap++;
			
		
		}
	}

	printf("%d", nswap);


	return 0;
}