/*
Description

Farmer John wants to repair a small length of the fence around the pasture. He measures the fence and finds that he needs N (1 ≤ N ≤ 20,000) planks of wood, each having some integer length Li (1 ≤ Li ≤ 50,000) units. He then purchases a single long board just long enough to saw into the N planks (i.e., whose length is the sum of the lengths Li). FJ is ignoring the "kerf", the extra length lost to sawdust when a sawcut is made; you should ignore it, too.

FJ sadly realizes that he doesn't own a saw with which to cut the wood, so he mosies over to Farmer Don's Farm with this long board and politely asks if he may borrow a saw.

Farmer Don, a closet capitalist, doesn't lend FJ a saw but instead offers to charge Farmer John for each of the N-1 cuts in the plank. The charge to cut a piece of wood is exactly equal to its length. Cutting a plank of length 21 costs 21 cents.

Farmer Don then lets Farmer John decide the order and locations to cut the plank. Help Farmer John determine the minimum amount of money he can spend to create the N planks. FJ knows that he can cut the board in various different orders which will result in different charges since the resulting intermediate planks are of different lengths.

Input

Line 1: One integer N, the number of planks 
Lines 2..N+1: Each line contains a single integer describing the length of a needed plank
Output

Line 1: One integer: the minimum amount of money he must spend to make N-1 cuts
Sample Input

3
8
5
8
Sample Output

34
Hint

He wants to cut a board of length 21 into pieces of lengths 8, 5, and 8. 
The original board measures 8+5+8=21. The first cut will cost 21, and should be used to cut the board into pieces measuring 13 and 8. The second cut will cost 13, and should be used to cut the 13 into 8 and 5. This would cost 21+13=34. If the 21 was cut into 16 and 5 instead, the second cut would cost 16 for a total of 37 (which is more than 34).
*/
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

int         n;
vector<ll>  ls;


int main()
{
    ll ans = 0ll;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        ll l;
        scanf("%lld", &l);
        ls.push_back(l);
    }

    while (n > 1) {

        int min1 = 0, min2 = 1;

        if (ls[min1] > ls[min2])    swap(min1, min2);

        for (int i=2; i<n; i++) 
            if (ls[i] < ls[min1]) {
                min2 = min1;
                min1 = i;
            }
            else if (ls[i] < ls[min2])
                min2 = i;

        ll t = ls[min1] + ls[min2];
        ans += t;

        if (min1 == n-1)    swap(min1, min2);

        ls[min1] = t;
        ls[min2] = ls[n-1];

        n --;   
    }

    printf("%lld\n", ans);

    return 0;

}
