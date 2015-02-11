/*
Description

Every cow's dream is to become the most popular cow in the herd. In a herd of N (1 <= N <= 10,000) cows, you are given up to M (1 <= M <= 50,000) ordered pairs of the form (A, B) that tell you that cow A thinks that cow B is popular. Since popularity is transitive, if A thinks B is popular and B thinks C is popular, then A will also think that C is 
popular, even if this is not explicitly specified by an ordered pair in the input. Your task is to compute the number of cows that are considered popular by every other cow. 
Input

* Line 1: Two space-separated integers, N and M 

* Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular. 
Output

* Line 1: A single integer that is the number of cows who are considered popular by every other cow. 
Sample Input

3 3
1 2
2 1
2 3
Sample Output

1
Hint

Cow 3 is the only cow of high popularity. 
*/
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int                 n, m;
vector<vector<int> > G, rG;
vector<bool>        used;
vector<int>         comp;
vector<int>         vs;

void dfs(int v)
{
    used[v] = true;
    for (int i=0; i<G[v].size(); i++) 
        if (!used[G[v][i]])
            dfs(G[v][i]);

    vs.push_back(v);
}

void rdfs(int v, int k)
{
    comp[v] = k;
    used[v] = true;
    for (int i=0; i<rG[v].size(); i++)
        if (!used[rG[v][i]])
            rdfs(rG[v][i], k);
}

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

int main()
{
    scanf("%d %d", &n, &m);

    G.resize(n);
    rG.resize(n);
    used.resize(n);
    comp.resize(n);

    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from --;
        to --;
        add_edge(from, to);
    }

    fill(used.begin(), used.end(), false);

    for (int i=0; i<n; i++)
        if (!used[i])
            dfs(i);

    fill(used.begin(), used.end(), false);

    int k = 0;
    for (int i=vs.size()-1; i>=0; i--)
        if (!used[vs[i]])
            rdfs(vs[i], k++);

    int root = -1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (comp[i] == k-1) {
            root = i;
            ans ++;
        }
    }

    bool connected = true;
    fill(used.begin(), used.end(), false);
    rdfs(root, -1);

    for (int i=0; i<n; i++)
        if (comp[i] >=0) {
            connected = false;
            break;
        }

    printf("%d", connected?ans:0);
    return 0;
}
