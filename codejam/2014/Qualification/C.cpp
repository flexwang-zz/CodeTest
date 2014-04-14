#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

#define min2(a, b) (a)<(b)?(a):(b)
#define LOOP	for(int y=0; y<r; y++) { for(int x=0; x<c; x++) {
#define INDEX (y*c+x)

void inline swap2(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int inline sqrtint(int x) {
	double r = sqrt((double)x);
	int r1 = (int)r +1;

	while (r1*r1 > x)
		r1 --;

	return r1;
}

int inline sqrint(int x) {
	return x*x;
}

int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<":";
		
		int r, c, m;

		cin >>r>>c>>m;

		int minsize = min2(r, c);

		int nnull = r*c - m;
		int root = sqrtint(nnull);

		if (m == 0) {
			cout <<endl;
			LOOP
					if (x==0 && y==0) {
						cout << 'c';
					}
					else {
						cout << '.';
					}
				}
				cout << endl;
			}
		}
		else if (minsize == 1) {
			cout <<endl;
			LOOP
					if (x==0 && y==0) {
						cout << 'c';
					}
					else if (INDEX < nnull) {
						cout << '.';
					}
					else {
						cout << '*';
					}
				}
				cout << endl;
			}
		}
		else if (nnull == 1) {
			cout << endl;
			LOOP
					if (x==0 && y==0) {
						cout << 'c';
						continue;
					}
					cout << '*';
				}
				cout << endl;
			}
		}
		else if (nnull <= 3 || nnull ==5 || nnull == 7) {
			cout << endl<<"Impossible" << endl;
		}
		else if (minsize == 2) {
			if (nnull %2) {
				cout << endl<<"Impossible" <<endl;
			}
			else {
				cout << endl;
				LOOP
						if (x==0 && y==0) {
							cout << 'c';
							continue;
						}
						if (minsize == r) {
							if (x < nnull/2) {
								cout << '.';
							}
							else {
								cout << '*';
							}
						}
						else {
							if (y < nnull/2) {
								cout << '.';
							}
							else {
								cout << '*';
							}
						}
					}
					cout << endl;
				}
				
			}

		}
		else if (minsize == 3 && false) {
		}
		else {
			if ((nnull / minsize) < 2) {
				if (nnull % 2) {
					cout << endl;
					for (int y=0; y<r; y++) {
						for (int x=0; x<c; x++) {
							if (x==0 && y==0) {
								cout << 'c';
								continue;
							}
							if (minsize == r) {
								if (x < 2 && y < (nnull/2-1) || (x==2) && y<3) {
									cout << '.';
								}		
								else {
									cout << '*';
								}
							}
							else {
								if (y < 2 && x < (nnull/2-1) || (y==2) && x<3) {
									cout << '.';
								}		
								else {
									cout << '*';
								}
							}
						}
						cout << endl;
					}
				}
				else if ((nnull %2) == 0) {
					cout << endl;
					for (int y=0; y<r; y++) {
						for (int x=0; x<c; x++) {
							if (x==0 && y==0) {
								cout << 'c';
								continue;
							}

							if (minsize ==r) {
								if (x <2 && y < nnull/2) {
									cout << '.';
								}
								else {
									cout << '*';
								}
							}
							else {
								if (y <2 && x < nnull/2) {
									cout << '.';
								}
								else {
									cout << '*';
								}
							}
						}
						cout << endl;
					}
				}
			}
			else if ((nnull / minsize) >= 2) {
				cout << endl;
				if (nnull %minsize == 1) {
					for (int y=0; y<r; y++) {
						for (int x=0; x<c; x++) {
							if (nnull / minsize > 2) {
								if (x==0 && y==0) {
									cout << 'c';
									continue;
								}
								if (minsize == r) {
									if ( (x < (nnull /minsize)+1)&&y<2 || (y!=(r-1)&&(x < (nnull /minsize))) || (y==(r-1)&&x < (nnull /minsize)-1)) {
										cout << '.';
									}
									else {
										cout << '*';
									}
								}
								else {
									if ( (y < (nnull /minsize)+1)&&x<2 || (x!=(c-1)&&(y < (nnull /minsize))) || (x==(c-1)&&y < (nnull /minsize)-1)) {
										cout << '.';
									}
									else {
										cout << '*';
									}
								}
							}
							else {
								if (x==0 && y==0) {
									cout << 'c';
									continue;
								}
								if (minsize == r) {
									if (x<2 && y <minsize-1 || y<3 && x == 2) {
										cout << '.';
									}
									else {
										cout << '*';
									}
								}
								else {
									if (y<2 && x <minsize-1 || x<3 && y == 2) {
										cout << '.';
									}
									else {
										cout << '*';
									}
								}
							}
						}
						cout << endl;
					}
					
				}
				else if (nnull % minsize != 1) {
					for (int y=0; y<r; y++) {
						for (int x=0; x<c; x++) {
							if (x==0 && y==0) {
								cout << 'c';
								continue;
							}
							if (minsize == r) {
									if ( x < nnull /minsize) {
										cout << '.';
									}
									else if ( x == nnull /minsize && y<nnull%minsize) {
										cout << '.';
									}
									else {
										cout << '*';
									}
							}
							else {
								if ( y < nnull/minsize) {
									cout << '.';
								}
								else if ( y == nnull /minsize && x<nnull%minsize) {
										cout << '.';
								}
								else {
									cout << '*';
								}
							}
						}
						cout << endl;
					}
					
				}
			}
		}
	}

	return 0;
}