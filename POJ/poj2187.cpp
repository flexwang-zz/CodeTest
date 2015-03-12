/*
Description

Bessie, Farmer John's prize cow, has just won first place in a bovine beauty contest, earning the title 'Miss Cow World'. As a result, Bessie will make a tour of N (2 <= N <= 50,000) farms around the world in order to spread goodwill between farmers and their cows. For simplicity, the world will be represented as a two-dimensional plane, where each farm is located at a pair of integer coordinates (x,y), each having a value in the range -10,000 ... 10,000. No two farms share the same pair of coordinates. 

Even though Bessie travels directly in a straight line between pairs of farms, the distance between some farms can be quite large, so she wants to bring a suitcase full of hay with her so she has enough food to eat on each leg of her journey. Since Bessie refills her suitcase at every farm she visits, she wants to determine the maximum possible distance she might need to travel so she knows the size of suitcase she must bring.Help Bessie by computing the maximum distance among all pairs of farms. 

Input

* Line 1: A single integer, N 

* Lines 2..N+1: Two space-separated integers x and y specifying coordinate of each farm 
Output

* Line 1: A single integer that is the squared distance between the pair of farms that are farthest apart from each other. 
Sample Input

4
0 0
0 1
1 1
1 0
Sample Output

2
Hint

Farm 1 (0, 0) and farm 3 (1, 1) have the longest distance (square root of 2) 
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct P
{
	double x, y;
	P(){}
	P(double xx, double yy):x(xx), y(yy){}
	P operator-(const P&p) const
	{
		return P(x-p.x, y-p.y);
	}
};
bool compare(const P&p1, const P&p2)
{
	if (p1.x != p2.x)	return p1.x < p2.x;
	return p1.y < p2.y;
}
double dot(const P&p1, const P&p2)
{
	return p1.x*p2.x + p1.y*p2.y;
}
double det(const P&p1, const P&p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}
double dist_sq(const P&p1, const P&p2)
{
	return dot((p1-p2),(p1-p2));
}
void convex_hull(vector<P>&q, vector<P>&p)
{
	sort(p.begin(), p.end(), compare);
	int k = 0;
	int n = p.size();
	q.resize(n*2);
	for (int i=0; i<n; i++) {
		while (k>1 && det((q[k-1]-q[k-2]),(p[i]-q[k-1])) < 0) k--;
		q[k++] = p[i];
	}
	for (int i=n-2, t=k; i>=0; i--) {
		while (k>t && det((q[k-1]-q[k-2]), (p[i]-q[k-1]))<0) k--;
		q[k++] = p[i];
	}
	q.resize(k-1);
}

void solve()
{
	int n;
	vector<P> p, q;
	scanf("%d", &n);
	p.resize(n);
	for (int i=0; i<n; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);
	convex_hull(q, p);
	double ans = 0;
	for (int i=0; i<q.size(); i++)
		for (int j=0; j<i; j++)
			ans = max(ans, dist_sq(q[i], q[j]));
	printf("%.0f\n", ans);
}

int main()
{
	solve();
	return 0;
}
