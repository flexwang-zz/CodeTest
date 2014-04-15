#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		int a[4][4];
		int r1, r2;
		vector<int> a1(4), a2(4);
		cin >> r1;

		for (int i=0; i<16; i++) {
			cin >> a[i/4][i%4];

			if (i/4 == r1-1) {
				a1[i%4] = a[i/4][i%4];
			}
		}

		cin >> r2;

		for (int i=0; i<16; i++) {
			cin >> a[i/4][i%4];

			if (i/4 == r2-1) {
				a2[i%4] = a[i/4][i%4];
			}
		}
		
		int nsame = 0;
		int answer = 0;
		for (int i=0; i<4; i++) {
			vector<int>::iterator iter = find(a2.begin(), a2.end(), a1[i]);

			if (iter != a2.end()) {
				answer = a1[i];
				nsame ++;
			}
			else {
				
			}
		}
		cout<<"Case #"<<t<<": ";
		if (nsame == 0) {
			cout << "Volunteer cheated!"<<endl;
		}
		else if (nsame == 1) {
			cout<<answer<<endl;
		}
		else {
			cout<<"Bad magician!"<<endl;
		}
	}

	return 0;
}