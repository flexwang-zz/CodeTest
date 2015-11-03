#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i] >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i=0; i<n; i++) 
        for (int c=b[i],d=a[i],l=b[i]; c<=m; l*=1.07,c+=l,d+=a[i]) 
            for (int v=c; v<=m; v++) 
                dp[i+1][v] = max(dp[i+1][v], dp[i][v-c]+d);
    cout << *max_element(dp[n].begin(), dp[n].end());
    return 0;
}