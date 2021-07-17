#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 100;
int n, m, d[26];
bool avail[maxN];
string a[maxN];

int main(){
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n >> m;
        n = n*2-1;
        for(int i=1; i<=n; ++i) cin >> a[i], avail[i] = true;
        for(int j=0; j<m; ++j){
            for(int i=0; i<26; ++i) d[i] = 0;
            for(int i=1; i<=n; ++i) ++ d[a[i][j]-'a'];
            for(int i=1; i<=n; ++i)
                if (d[a[i][j]-'a'] % 2 == 0) avail[i] = false;
        }
        for(int i=1; i<=n; ++i)
        if (avail[i]){
            cout << a[i] << '\n';
            break;
        }
    }
    return 0;
}
