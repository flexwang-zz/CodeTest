#include<stdio.h>
#include<vector>

using namespace std;

struct node
{
	int key;
	int time;

	node(){}
	node(int k):key(k), time(1){}
};

vector<int> primes;
bool isprime(int p);

int main()
{
	int m;

	scanf("%d", &m);

	printf("%d=", m);

	if (m == 1) {
		printf("1");
		return 0;
	}
	vector<node> factors;
	int p = 2;
	while (m > 1)
	{
		while (m%p == 0) {
			if (factors.size())
			{
				if (factors.back().key == p) {
					factors.back().time ++;
				}
				else {
					factors.push_back(node(p));
				}
			}
			else
			{
				factors.push_back(node(p));
			}

			m /= p;
		}

		while (!isprime(++p))
			;
	}

	for (int i=0; i<factors.size(); i++) {
	
		if (i)	printf("*");

		printf("%d", factors[i].key);

		if (factors[i].time > 1) {
			printf("^%d", factors[i].time);
		}
	}
	return 0;
}

bool isprime(int p)
{
	for (int i=0; i<primes.size(); i++) {
		if (p!=primes[i] && p%primes[i] == 0) {
			return false;
		}
	}
	primes.push_back(p);
	
	return true;
}
