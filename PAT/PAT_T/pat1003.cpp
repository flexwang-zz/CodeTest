/*
After finishing her tour around the Earth, CYLL is now planning a universal travel sites development project. After a careful investigation, she has a list of capacities of all the satellite transportation stations in hand. To estimate a budget, she must know the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.

Input Specification:

Each input file contains one test case. For each case, the first line contains the names of the source and the destination planets, and a positive integer N (<=500). Then N lines follow, each in the format:

sourcei destinationi capacityi

where sourcei and destinationi are the names of the satellites and the two involved planets, and capacityi > 0 is the maximum number of passengers that can be transported at one pass from sourcei to destinationi. Each name is a string of 3 uppercase characters chosen from {A-Z}, e.g., ZJU.

Note that the satellite transportation stations have no accommodation facilities for the passengers. Therefore none of the passengers can stay. Such a station will not allow arrivals of space vessels that contain more than its own capacity. It is guaranteed that the list contains neither the routes to the source planet nor that from the destination planet.

Output Specification:

For each test case, just print in one line the minimum capacity that a planet station must have to guarantee that every space vessel can dock and download its passengers on arrival.

Sample Input:
EAR MAR 11
EAR AAA 300
EAR BBB 400
AAA BBB 100
AAA CCC 400
AAA MAR 300
BBB DDD 400
AAA DDD 400
DDD AAA 100
CCC MAR 400
DDD CCC 200
DDD MAR 300
Sample Output:
700

*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

struct edge{int to, cap, rev;
edge(int t, int c, int r):to(t), cap(c), rev(r){}
};

const int MAX_N = 26*26*26+2;
map<string, int>        name_table;
int                     nnode;
vector<edge>            G[MAX_N];
vector<bool>            used;


int str2int(string& str) {
    if (!name_table.count(str)) {
        int id = nnode ++;
        name_table[str] = id;
        return id;
    }
    return name_table[str];
}

void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

int dfs(int v, int s, int f)
{
    if (v == s) return f;
    used[v] = true;

    for (int i=0; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, s, min(e.cap, f));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;

                return d;
            }
        }
    }

    return 0;

}

int main()
{
    string src, dest;
    int nedge;
    cin >> src >> dest >> nedge;

    int s = str2int(src);
    int t = str2int(dest);

    for (int i=0; i<nedge; i++) {
        string src, dest;
        int cap;
        cin >> src >> dest >> cap;
        int from = str2int(src);
        int to = str2int(dest);

        add_edge(from, to, cap);
    }

    int max_flow = 0;
    for (;;) {
        used.assign(nnode, false);
        int f = dfs(s, t, INT_MAX);
        
        if (f == 0) break;
        max_flow += f;
    }

    printf("%d\n", max_flow);

    return 0;
}
