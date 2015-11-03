#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string str) {
    vector<int> next(str.length()+1);
    next[0] = -1;
    for (int i=1; i<=str.length(); i++) {
        int k = next[i-1];
        while (k>=0 && str[k] != str[i-1])
            k = next[k];
        next[i] = k+1;
    }
    return next;
}

int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--) {
        string a, b;
        cin >> a >> b;
        vector<int> next = getNext(a);
        int cnt = 0;
        for (int i=0,j=0; i<b.length(); i++) {
            while (j>=0 && b[i] != a[j])
                j = next[j];
            j++;
            if (j == a.length()) {
                j = next[j];
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}