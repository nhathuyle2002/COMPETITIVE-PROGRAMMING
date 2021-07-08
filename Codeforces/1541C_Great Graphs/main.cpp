#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;
long long a[maxN], ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        ans = a[n];
        long long sum = a[1];
        for(int i=2; i<=n; ++i){
            ans -= a[i]*(i-1) - sum;
            sum += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
