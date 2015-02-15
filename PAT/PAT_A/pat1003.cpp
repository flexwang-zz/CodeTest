/*﻿As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4
*/

#include <stdio.h>

typedef int Vertex;

struct TableEntry
{
	Vertex Adjacent[500];
	int L[500];
	int NAdjacent;
	int Dist;
	int NPath;
	int NTeam;
	int TotalTeam;
	bool Known;
};

#define NotAVertex (-1)
#define MaxDist (-1)

void Dikstra(TableEntry* T, int NCity);

int main()
{
	int NCity, NRoad;
	Vertex from , to;
	struct TableEntry City[500];
 
	scanf("%d %d %d %d", &NCity, &NRoad, &from, &to);
	for( int i=0; i<NCity; i++)
	{
		int NTeam;
		scanf("%d", &NTeam);
   
		City[i].NTeam = NTeam;    
		City[i].Known = false;
		City[i].NAdjacent = 0;
   
		if( i == from )
		{
			City[i].Dist = 0;
			City[i].NPath = 1;
			City[i].TotalTeam = NTeam;
		}
		else
		{
			City[i].Dist = MaxDist;
			City[i].NPath = 0;
			City[i].TotalTeam = 0;
		}
     
	}
 
	for( int i=0; i<NRoad; i++)
	{
		int v1, v2, L;
		scanf("%d %d %d" , &v1, &v2, &L);
		City[v1].Adjacent[City[v1].NAdjacent] = v2;
		City[v1].L[City[v1].NAdjacent] = L;
		City[v2].Adjacent[City[v2].NAdjacent] = v1;
		City[v2].L[City[v2].NAdjacent] = L;
   
		City[v1].NAdjacent++;
		City[v2].NAdjacent++;
		}
 

	Dikstra(City, NCity);
 
	printf("%d %d", City[to].NPath, City[to].TotalTeam);
 
	return 0;
}

void Dikstra(TableEntry* T, int NCity)
{  
	for(;;)
	{
		//V = smallest unknown distanc vertex;
		int min = MaxDist;
		int nmin = 0;
		Vertex vmin[500];
		for(int i=0; i<NCity; i++)
		{
			if( T[i].Known || T[i].Dist == MaxDist)
			{
     		continue;
     		}
			if( min == MaxDist || min > T[i].Dist )
			{
				vmin[0] = i;
				nmin = 1;
				min = T[i].Dist;
			}
			else if( min == T[i].Dist )
			{
				vmin[nmin++] = i;
			}
		}
   
		if( nmin <= 0 )
			break;
	   
	   //printf("nmin: %d min: %d\n", nmin, min);
		 
		for( int j=0; j<nmin; j++)
		{
			int index = vmin[j];
			//  printf("%d ", index);
			T[index].Known = true;
	   
			for( int k=0; k<T[index].NAdjacent; k++)
			{
				if( !T[T[index].Adjacent[k]].Known )
				{
					if( T[T[index].Adjacent[k]].Dist == MaxDist || T[index].Dist + T[index].L[k] < T[T[index].Adjacent[k]].Dist)
					{
						T[T[index].Adjacent[k]].Dist = T[index].Dist + T[index].L[k];
						T[T[index].Adjacent[k]].NPath = T[index].NPath;
						T[T[index].Adjacent[k]].TotalTeam = T[index].TotalTeam + T[T[index].Adjacent[k]].NTeam;
		 			}
		 			else if(T[index].Dist + T[index].L[k] == T[T[index].Adjacent[k]].Dist)
		 			{
						T[T[index].Adjacent[k]].NPath += T[index].NPath;
						if( (T[T[index].Adjacent[k]].NTeam + T[index].TotalTeam) > T[T[index].Adjacent[k]].TotalTeam )
						{
							T[T[index].Adjacent[k]].TotalTeam = T[T[index].Adjacent[k]].NTeam + T[index].TotalTeam;
						}
					}	
				}
			}
	   	}
	}
}
