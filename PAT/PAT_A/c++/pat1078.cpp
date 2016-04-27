/*
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

inline bool isprime(int n) {
	if (n <= 2)	return n ==2;

	for (int i=2; i<=(int)sqrt((float)n); i++) {
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

int main()
{
	int msize, n;
	

	scanf("%d %d", &msize, &n);

	vector<int> v(n);

	while (!isprime(msize)) 
		msize ++;

	vector<bool> table(msize, false);
	for (int i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i=0; i<n; i++) {
		int h = v[i]%msize;

		int shift = 0;

		while (shift < msize && table[(h+shift*shift)%msize]) {
			shift ++;
		}
		if (i) {
			printf(" ");
		}

		if (shift < msize) {
			table[(h+shift*shift)%msize] = true;
			printf("%d", (h+shift*shift)%msize);
		}
		else {
			printf("-");
		}
	}

	return 0;
}