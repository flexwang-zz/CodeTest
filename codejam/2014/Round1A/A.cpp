#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

typedef long long LL;

#define INF 1e6

vector<LL> f;
int time;


inline int bitcount(LL n) {
	unsigned int c =0 ; 
    while (n >0)
    {
        if((n &1) ==1) 
            ++c ;
        n >>=1 ; 
    }
    return c ;
}

inline void Permutation(int start, int end, vector<LL> list, LL lastr)
{
	int i;
	if (start >= end) 
	{
		LL result = f[start-1]^list[start-1];

		if (result == lastr) {
			time = min(time, bitcount(result));
		}

		return;
	}

	for (i = start; i < end; i++) 
	{
		
		LL result = f[start]^list[i];
		if (lastr < 0 || lastr == result) {
			swap(list[i], list[start]);
			Permutation(start+1, end, list, result);
			swap(list[i], list[start]);
		}
	}
}
int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int n, l;
		cin >> n >> l;

		vector<string> flow(n), require(n);

		for (int i=0; i<n; i++) {
			cin >> flow[i];
		}

		for (int i=0; i<n; i++) {
			cin >> require[i];
		}

		vector<LL> r(n);
		f = vector<LL>(n);
		for (int i=0; i<n; i++) {

			f[i] = 0;
			r[i] = 0;
			for (int j=0; j<l; j++) {
				f[i] <<= 1;
				f[i] += flow[i][j]=='1';

				r[i] <<= 1;
				r[i] += require[i][j]=='1';
			}
		}

		time = INF;

		Permutation(0, n, r, -1);

		if (time == INF) {
			cout << "NOT POSSIBLE" << endl;
		}
		else {
			cout << time << endl;
		}
	}

	return 0;
}

