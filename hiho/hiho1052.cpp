#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--) {
        string str;
        int k;
        cin >> str >> k;
        int cnt = 0, offset = str.length()-k;
        for (int i=0; i<k&&i<offset; i++) {
            unordered_map<char, int> um;
            for (int j=i; j<str.length(); j+=offset)
                um[str[j]]++;
            int sum=0, m=0;
            for (auto x:um)
                sum += x.second, m=max(m, x.second);
            cnt += sum-m;
        }
        cout << cnt;
        if (ncase) cout << endl;
    }
    return 0;
}