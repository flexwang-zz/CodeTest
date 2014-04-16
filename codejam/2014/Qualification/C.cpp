#include <iostream>

using namespace std;

char ch[51][51];

bool solve(int r, int c, int m) {
	memset(ch, '\0', sizeof(ch));
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			ch[i][j] = '*';
		}
	}

	int nnull = r*c -m;

	if (m == 0) {
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				ch[i][j] = '.';
			}
		}	
		ch[0][0] = 'c';

		return true;
	}

	if (r == 1) {
		for (int i=0; i<nnull; i++) {
			ch[0][i] = '.';
		}
		ch[0][0] = 'c';

		return true;
	}

	if (nnull == 1) {
		ch[0][0] = 'c';

		return true;
	}

	if (nnull <=3 || nnull ==5 || nnull == 7) {
		return false;
	}

	if (r == 2) {
		if (nnull%2)	return false;
		else {
			for (int i=0; i<nnull/2; i++) {
				ch[0][i] = '.';
				ch[1][i] = '.';
			}
			ch[0][0] = 'c';

			return true;
		}
	}

	if (nnull / r <= 2) {
		if (nnull %2 ) {
			for (int y=0; y<r; y++) {
				for (int x=0; x<c; x++) {
					if (x < 2 && y < (nnull/2-1) || (x==2) && y<3) {
						ch[y][x] = '.';
					}
				}
			}
		}
		else {
			for (int x=0; x< min(c, nnull /2); x++) {
				ch[x][0] = '.';
				ch[x][1] = '.';
			}
			if ( nnull > r*2) {
				for (int i=0; i<nnull - 2*r; i++) {
					ch[i][2] = '.';
				}
			}
		}
		ch[0][0] = 'c';

		return true;
	}

	if (nnull%r == 1) {
		for (int y=0; y<r; y++) {
			for (int x=0; x<c; x++) {
				if ( (x==nnull/r && y<2 )|| (y==(r-1) && (x < (nnull /r)-1)) || (y!=(r-1)&&(x < (nnull /r)))) {
					ch[y][x] = '.';
				}
			}
		}

		ch[0][0] = 'c';

		return true;
	}

	for (int y=0; y<r; y++) {
		for (int x=0; x<c; x++) {

			if ( x < nnull/r) {
				ch[y][x] = '.';
			}
			else if ( x == nnull/r && y<nnull%r) {
				ch[y][x] = '.';
			}
		}
	}

	ch[0][0] = 'c';

	return true;

}

int main()
{
	int T;
	cin >>T;

	for (int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<":"<<endl;

		int r, c, m;
		bool inv = false;
		cin >>r>>c>>m;

		if (r > c) {
			int tmp = r;
			r = c;
			c = tmp;
			inv = true;
		}

		if (solve(r, c, m)) {
			if (inv) {
				for (int j = 0; j < c; ++j) {
					for (int i = 0; i < r; ++i)
						cout << ch[i][j];
					cout << endl;
				}
			} else {
				for (int i = 0; i < r; ++i) cout << ch[i]<<endl;
			}
		}
		else {
			cout << "Impossible"<<endl;
		}

	}

	return 0;
}