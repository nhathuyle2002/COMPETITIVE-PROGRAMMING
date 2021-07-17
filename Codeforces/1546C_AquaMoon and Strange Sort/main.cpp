#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n, a[maxN], d[maxN][2];

int sole(int l, int r){
    return (r+1)/2 - l/2;
}
int sochan(int l, int r){
    return r/2 - (l-1)/2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i], ++d[a[i]][i%2];
        int endpre = 0;
        bool ans = true;
        for(int x=0; x<maxN; ++x){
            int nexend = endpre + d[x][0] + d[x][1];
            if (sochan(endpre+1, nexend) != d[x][0] || sole(endpre+1, nexend) != d[x][1]){
                ans = false;
                break;
            }
            endpre = nexend;
        }
        if (ans) cout << "YES\n"; else cout << "NO\n";
        for(int i=1; i<=n; ++i) --d[a[i]][i%2];
    }
    return 0;
}
