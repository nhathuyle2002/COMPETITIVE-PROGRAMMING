#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
const int maxN = 5e5+100;
int n;
map<LL, LL> mp;
LL a[maxN], b[maxN], ans = 0;

void solve(){
    LL cur = 0;
    int j = n;
    for(int i=1; i<=n; ++i){
        while (cur < b[i] && i <= j){
            LL delta = min(b[i]-cur, a[j]);
            cur += delta;
            ans += delta*2;
            a[j] -= delta;
            if (a[j] == 0) --j;
        }
        if (i > j) return;
        ans += a[i];
        cur += a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i){
        LL x, y; cin >> x >> y;
        mp[y] += x;
    }
    n = 0;
    for(pair<LL, LL> p: mp){
        ++n;
        b[n] = p.first; a[n] = p.second;
    }
    solve();
    cout << ans;
}
