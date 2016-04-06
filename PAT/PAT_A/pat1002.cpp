/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/

#include <stdio.h>
#include <vector>

using namespace std;

const int max_n = 1001;
float a[max_n], b[max_n], c[max_n];

void read_poly(float a[]) {
	for (int i=0; i<max_n; ++i)
		a[i] = 0.f;
	int k;
	scanf("%d", &k);
	for (int i=0; i<k; ++i) {
		int x;
		float y;
		scanf("%d %f", &x, &y);
		a[x] = y;
	}
}

int main()
{
	read_poly(a);
	read_poly(b);
	vector<pair<int, float> > res;
	for (int i=0; i<max_n; ++i) 
		if (a[i] + b[i] != 0.f)
			res.push_back(make_pair(i, a[i]+b[i]));
	if (res.size() == 0) 
		printf("0");
	else {
		printf("%d ", res.size());
		for (int i=res.size()-1; i>=0; --i) {
			printf("%d %.1f%c", res[i].first, res[i].second, i==0?'\n':' ');
		}
	}
	return 0;

}