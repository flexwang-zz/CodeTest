/*
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line a separated by a space.

Output Specification:

For each test case, simply print in a line the maximum length of Eva's favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/

#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int ncolor, norder;

	scanf("%d %d", &ncolor, &norder);

	vector<int> color;
	vector<int> order(ncolor+1, 0);

	for( int i=0; i<norder; i++)
	{
		int c;

		scanf("%d", &c);

		order[c] = i+1;
	}

	int len;

	scanf("%d", &len);

	for(int i=0; i<len; i++)
	{
		int c;

		scanf("%d", &c);

		if( order[c] > 0)
		{
			color.push_back(order[c]);
		}
	}

	// 最长不降子序列



	int size = color.size();
	
	vector<int> F(size, 0);

	F[0] = 1;
	int totalmax = 1;

	for( int i=1; i<size; i++)
	{
		int max = 1;

		for(int j=0; j<i; j++)
		{
			if( color[j] <= color[i] && (F[j]+1)>max)
			{
				max = F[j]+1;
			}
		}
		F[i] = max;

		if( F[i] > totalmax)
		{
			totalmax = F[i];
		}
	}
	
	printf("%d", totalmax);
	
	return 0;
}