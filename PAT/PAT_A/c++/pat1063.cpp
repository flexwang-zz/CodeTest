/*
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/
#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	map<int,vector<int>> Map;
	int nset;

	scanf("%d", &nset);

	vector<vector<int>> table(nset);

	for( int i=0; i<nset; i++)
	{
		table[i] = vector<int>(nset,0);
	}

	for( int i=0; i<nset; i++)
	{
		int nmem;
		scanf("%d", &nmem);

		for( int j=0; j<nmem; j++)
		{
			int val;
			scanf("%d", &val);

			if( find(Map[val].begin(), Map[val].end(), i) != Map[val].end())
			{
			}
			else
			{
				Map[val].push_back(i);
				for( int k=0, size=Map[val].size(); k<size; k++)
				{
					int one=i;
					int another = Map[val][k];

					if( one < another)
					{
						table[one][another]++;
					}
					else
					{
						table[another][one]++;
					}

					//table[one][another]++;
					//table[another][one]++;
				}
			}
		}
	}

	int nquery;

	scanf("%d", &nquery);
	
	for( int i=0; i<nquery; i++)
	{
		int one, another;

		scanf("%d %d", &one, &another);

		one--;
		another--;

		int ncommon;

		if( one < another)
		{
			ncommon = table[one][another];
		}
		else
		{
			ncommon = table[another][one];
		}

		float ratio = (float)ncommon/(table[one][one]+table[another][another]-ncommon)*100;
		printf("%.1f%%\n", ratio);
	}

	return 0;
}
