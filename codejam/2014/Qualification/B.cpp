#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define min2(a, b) (a)<(b)?(a):(b)

int main()
{
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout<<"Case #"<<t<<": ";

		double c, f, x;
		cin>>c>>f>>x;
		
		double mintime;

		double d0 = f*c-f*x+2*c;

		if (d0 > 0) {
			mintime = x/2.f;
		}
		else {
			double n = (f*x-2*c)/(f*c);
			
			int n1 = (int)n;
			int n2 = n1 + 1;

			double time_for_farm = 0.;

			for (int i=0; i<n1; i++) {
				time_for_farm += c/(2.+i*f);
			}
			double time1 = x/(2.+n1*f)+time_for_farm;
			double time2 = x/(2.+n2*f)+time_for_farm+c/(2.+(n2-1)*f);

			mintime = min2(time1, time2);
		}

		printf("%.7f\n", mintime);
	}

	return 0;
}