#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	a += b;

	if( a < 0)
	{
		printf("-");
		a = -a;
	}

	vector<int> digits;
	do
	{
		digits.insert(digits.begin(), a%10);
		a /= 10;
	}while(a > 0);

	for( int i=0, size=digits.size(); i<size; i++)
	{
		if(  (size-i)%3 == 0 && i)
		{
			printf(",");
		}
		printf("%d", digits[i]);
	}

	return 0;
}