#include <bits/stdc++.h>
//#pragma GCC optimize ("O2, unroll-loops")
//#pragma GCC optimize ("no-stack-protector, fast-math")
using namespace std;

const int maxN =4e5+100;
int n;
int a[maxN];
int64_t ans;


int main()
{
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        a[0] = 0; a[n+1] = 0;
        ans = 0;

        for(int i=1; i<=n; ++i)
        if (a[i] > a[i-1] && a[i] > a[i+1]){
            int d = max(a[i-1], a[i+1]);
            ans += a[i] - d;
            a[i] = d;
        }

        for(int i=1; i<=n+1; ++i)
            ans += abs(a[i]-a[i-1]);

        cout << ans << '\n';
    }
    return 0;
}
