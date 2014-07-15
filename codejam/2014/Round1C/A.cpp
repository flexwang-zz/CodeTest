#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;

typedef long long LL;

const LL base = 1LL << 40;

inline LL gcd(LL a, LL b) {
	if (b > a) {
		swap(a, b);
	}

	while (b) {
		LL d = a%b;
		a = b;
		b = d;
	}

	return a;
}

inline bool isvalid(LL a) {
	if ( a > base)	return false;

	LL p = 1;

	while (p < a) {
		p <<= 1;
	}

	return p == a;
}

int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";

		LL p, q;

		string str;

		cin >> str;

		std::replace(str.begin(), str.end(), '/', ' ');

		istringstream is(str);

		is >>p >> q;

		LL g = gcd(p, q);

		p /= g;
		q /= g;

		if (!isvalid(q)) {
			cout << "impossible" << endl;
			continue;
		}

		p *= base/q;

		int result = 0;
		int i = 0;
		while (p) {
			if (p&1LL) {
				result = i;
			}

			i ++;
			p >>= 1;
		}

		cout << 40-result << endl;
	}
	return 0;
}