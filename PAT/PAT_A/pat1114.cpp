/*
This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:

ID Father Mother k Child1 ... Childk M_estate Area

where ID is a unique 4-digit identification number for each person; Father and Mother are the ID's of this person's parents (if a parent has passed away, -1 will be given instead); k (0<=k<=5) is the number of children of this person; Childi's are the ID's of his/her children; M_estate is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate.

Output Specification:

For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:

ID M AVG_sets AVG_area

where ID is the smallest ID in the family; M is the total number of family members; AVG_sets is the average number of sets of their real estate; and AVG_area is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.

Sample Input:
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
Sample Output:
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>


using namespace std;

struct person
{
    int s;
    double a;
    vector<int> children;
    bool visited;
    person():visited(false), s(0), a(0.0){}
};

struct out
{
    int id, n;
    double as, aa;
    out():id(99999), n(0), as(0.0), aa(0.0){}
    bool operator<(const out &o) const {
        if (o.aa == aa)
            return id < o.id;
        return aa > o.aa;
    }
};


const int max_n = 1001;
unordered_map<int, person> ps;
int n;

void dfs(int id, out &o) {
    if (ps[id].visited) return;
    ps[id].visited = true;
    o.n ++;
    o.id = min(o.id, id);
    o.as += ps[id].s;
    o.aa += ps[id].a;
    for (auto t:ps[id].children)
        dfs(t, o);
}


int main()
{
    cin >> n;
    for (int i=0; i<n; ++i) {
        int id, f, m, nc;
        cin >> id >> f >> m >> nc;
        person p;
        p.children.resize(nc);
        for (auto &x:p.children)
            cin >> x;
        if (f >= 0) p.children.push_back(f);
        if (m >= 0) p.children.push_back(m);
        cin >> p.s >> p.a;
        ps.insert(make_pair(id, p));
    }
    unordered_map<int, person>  um;
    for (auto p:ps)
        for (auto x:p.second.children)
            if (ps.count(x))
                ps[x].children.push_back(p.first);
            else
                um[x].children.push_back(p.first);
    for (auto p:um)
        ps.insert(p);

    vector<out> res;
    for (auto &p :ps) 
        if (!p.second.visited) {
            out o;
            dfs(p.first, o);
            o.as /= o.n;
            o.aa /= o.n;
            res.push_back(o);
        }
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (auto &x : res)
        printf("%04d %d %.3f %.3f\n", x.id, x.n, x.as, x.aa);

    return 0;
}