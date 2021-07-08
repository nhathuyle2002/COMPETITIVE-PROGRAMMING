#include <bits/stdc++.h>
//#pragma GCC optimize ("O2, unroll-loops")
//#pragma GCC optimize ("no-stack-protector, fast-math")
using namespace std;

const int maxN =4e5+100;
const int MOD = 1e9+7;
int n;
int a[maxN], b[maxN], posa[maxN];;
bool d[maxN];
int64_t ans;

void dfs(int i){
    if (!d[i]) return;
    d[i] = false;
    dfs(posa[b[i]]);
}

int main()
{
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<=n; ++i) cin >> b[i];

        ans = 0;
        for(int i=1; i<=n; ++i)
        if (a[i] == b[i]){
            ans = -1;
            break;
        }
        if (ans == -1){
            cout << "0\n";
            continue;
        }

        int cnt = 0;
        for(int i=1; i<=n; ++i) d[i]=true, posa[a[i]] = i;
        for(int i=1; i<=n; ++i)
            if (d[i]) ++cnt, dfs(i);

        ans = 1;
        for(int t=1; t<=cnt; ++t) ans = ans *2 % MOD;
        cout << ans << '\n';
    }
    return 0;
}
