#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;
long long res, a[maxN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        res = 0;
        for(int i=1; i<n; ++i) res = max(res, a[i]*a[i+1]);
        cout << res << '\n';
    }
    return 0;
}
