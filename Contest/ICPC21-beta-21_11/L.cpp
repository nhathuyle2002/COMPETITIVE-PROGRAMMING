#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;

int64_t n;
vector<int64_t> ans;

void solve(){
    ans.clear();
    if (n%2 == 1) return;

    for(int64_t x=1; x*x*x <=n; ++x)
        if (n%x == 0 && n%(x+1) == 0) ans.push_back(x);

    for(int64_t k=1; ; ++k){
        int64_t m = n/k;
        int64_t x = (sqrt(1 + 4*m)-1) / 2;
        if (x==0 || n/x/x/x > 0) break;
        if (n%k == 0 && x*(x+1) == m) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test --){
        cin >> n;
        solve();
        if (ans.empty()) cout << "-1\n"; else{
            for(int64_t x: ans) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
