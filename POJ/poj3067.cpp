/*
Description

Japan plans to welcome the ACM ICPC World Finals and a lot of roads must be built for the venue. Japan is tall island with N cities on the East coast and M cities on the West coast (M <= 1000, N <= 1000). K superhighways will be build. Cities on each coast are numbered 1, 2, ... from North to South. Each superhighway is straight line and connects city on the East coast with city of the West coast. The funding for the construction is guaranteed by ACM. A major portion of the sum is determined by the number of crossings between superhighways. At most two superhighways cross at one location. Write a program that calculates the number of the crossings between superhighways.
Input

The input file starts with T - the number of test cases. Each test case starts with three numbers ¨C N, M, K. Each of the next K lines contains two numbers ¨C the numbers of cities connected by the superhighway. The first one is the number of the city on the East coast and second one is the number of the city of the West coast.
Output

For each test case write one line on the standard output: 
Test case (case number): (number of crossings)
Sample Input

1
3 4 4
1 4
2 3
3 2
3 1
Sample Output

Test case 1: 5
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> R;
typedef long long ll;
const int   max_n = 1024;
ll			blt[max_n];
int         n, m;
vector<R>   r;
void    init()
{
    memset(blt, 0, sizeof(blt));
}

void    add(int k) {
    while (k <= max_n) {
        blt[k] += 1;
        k += k&-k;
    }
}

ll     sum(int k) {
    ll ans = 0;
    while (k > 0) {
        ans += blt[k];
        k -= k&-k;
    }
    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int ic=1; ic<=ncase; ic++) {
        init();
        int k;
        scanf("%d%d%d", &n, &m, &k);
        r.resize(k);
        for (int i=0; i<k; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            r[i].first = a;
            r[i].second = b;
        }
        sort(r.begin(), r.end(), greater<R>());
        ll ans = 0;
        for (int i=0; i<k; i++) {
            ans += sum(r[i].second-1);
			add(r[i].second);
        }
        printf("Test case %d: %lld\n", ic, ans);
    }
    return 0;
}