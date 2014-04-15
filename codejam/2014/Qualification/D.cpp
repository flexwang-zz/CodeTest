#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": ";

		int n;

		cin >>n;

		vector<float> a1(n);
		vector<float> a2(n);

		for (int i=0; i<n; i++) {
			cin >> a1[i];
		}

		for (int i=0; i<n; i++) {
			cin >> a2[i];
		}

		sort(a1.begin(), a1.end(), greater<float>());
		sort(a2.begin(), a2.end(), greater<float>());


		int score = 0;
		int i2 = 0;
		for (int i=0; i<n; i++) {	
			if (a1[i2] < a2[i]) {
			}
			else {
				score ++;
				i2 ++;
			}
		}

		cout << score;

		score = 0;
		i2 = 0;
		for (int i=0; i<n; i++) {	
			if (a2[i2] < a1[i]) {
			}
			else {
				score ++;
				i2 ++;
			}
		}

		score = n - score;
		cout << " "<<score;

		cout << endl;
	}
}