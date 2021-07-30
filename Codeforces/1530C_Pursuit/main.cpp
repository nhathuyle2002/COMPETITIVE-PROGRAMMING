#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n, a[maxN], b[maxN];

int calca(int i){
    if (i <= n) return a[i]; else{
        return a[n] + (i-n)*100;
    }
}

int calcb(int t){
    if (t/4 <= t-n) return b[n]; else{
        int t2 = t/4 - (t-n);
        return b[n] - b[t2];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        sort(a+1, a+n+1, [](int x, int y){return x < y;});
        for(int i=1; i<=n; ++i) cin >> b[i];
        sort(b+1, b+n+1, [](int x, int y){return x < y;});
        for(int i=1; i<=n; ++i) a[i] += a[i-1], b[i] += b[i-1];
        if (a[n] - a[n/4] >= b[n] - b[n/4]){
            cout << 0 << '\n';
            continue;
        }
        int L = 1, R = maxN;
        while (L < R){
            int M = (L + R) / 2;
            int t = n + M;
            if (calca(t) - calca(t/4) >= calcb(t)) R = M; else L = M + 1;
        }
        cout << L << '\n';
    }
    return 0;
}
