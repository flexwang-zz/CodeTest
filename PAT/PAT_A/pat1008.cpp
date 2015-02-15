
#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int curfloor = 0;
	int ntime = 0;
	for(int i=0;i<n;i++)
	{
		int floor;
		scanf("%d", &floor);
		int nfloor = floor - curfloor;

		if( nfloor > 0)
		{
			ntime += nfloor*6;
		}
		else if( nfloor < 0)
		{
			ntime += (-nfloor)*4;
		}
		ntime += 5;

		curfloor = floor;
	}

	printf("%d", ntime);

	return 0;
}
