/*
Description

Cows are such finicky eaters. Each cow has a preference for certain foods and drinks, and she will consume no others.

Farmer John has cooked fabulous meals for his cows, but he forgot to check his menu against their preferences. Although he might not be able to stuff everybody, he wants to give a complete meal of both food and drink to as many cows as possible.

Farmer John has cooked F (1 ¡Ü F ¡Ü 100) types of foods and prepared D (1 ¡Ü D ¡Ü 100) types of drinks. Each of his N (1 ¡Ü N ¡Ü 100) cows has decided whether she is willing to eat a particular food or drink a particular drink. Farmer John must assign a food type and a drink type to each cow to maximize the number of cows who get both.

Each dish or drink can only be consumed by one cow (i.e., once food type 2 is assigned to a cow, no other cow can be assigned food type 2).

Input

Line 1: Three space-separated integers: N, F, and D 
Lines 2..N+1: Each line i starts with a two integers Fi and Di, the number of dishes that cow i likes and the number of drinks that cow i likes. The next Fi integers denote the dishes that cow i will eat, and the Di integers following that denote the drinks that cow i will drink.
Output

Line 1: A single integer that is the maximum number of cows that can be fed both food and drink that conform to their wishes
Sample Input

4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3
Sample Output

3
Hint

One way to satisfy three cows is: 
Cow 1: no meal 
Cow 2: Food #2, Drink #2 
Cow 3: Food #1, Drink #1 
Cow 4: Food #3, Drink #3 
The pigeon-hole principle tells us we can do no better since there are only three kinds of food or drink. Other test data sets are more challenging, of course.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

const int max_n=1000;

struct edge{
    int to, cap, rev;
    edge(int t, int c, int r):to(t), cap(c), rev(r){}
};

vector<edge>    G[max_n];
bool            used[max_n];
int             n, f, d;

void add_edge(int from, int to) {
    G[from].push_back(edge(to, 1, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

int dfs(int v, int t, int f)
{
    used[v] = true;

    if (v == t) return f;

    for (int i=0; i<G[v].size(); i++) {
        edge &e = G[v][i];

        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(e.cap, f));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

int max_flow(int s, int t)
{
    int ans = 0;

    for (;;) {
        fill(used, used+max_n, false);
        int f = dfs(s, t, INT_MAX);
        if (f == 0) break;
        ans += f;
    }

    return ans;
}

int main()
{
    scanf("%d %d %d", &n, &f, &d);

    int s = 0, t = 1;
    for (int i=0; i<n; i++) 
        add_edge(2+i, 2+n+i);
    
    for (int i=0; i<f; i++)
        add_edge(s, 2+2*n+i);

    for (int i=0; i<d; i++) 
        add_edge(2+2*n+f+i, t);

    for (int i=0; i<n; i++) {
        int nf, nd;
        scanf("%d %d", &nf, &nd);

        for (int j=0; j<nf; j++) {
            int food;
            scanf("%d", &food);
            food --;
            food += 2+2*n;
            add_edge(food, 2+i);
        }

        for (int j=0; j<nd; j++) {
            int drink;
            scanf("%d", &drink);
            drink--;
            drink += 2+2*n+f;
            add_edge(2+n+i, drink);
        }
    }

    printf("%d", max_flow(s, t));

    return 0;
}
