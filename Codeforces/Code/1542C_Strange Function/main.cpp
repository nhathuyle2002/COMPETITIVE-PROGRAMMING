#include <bits/stdc++.h>
using namespace std;

const long long maxN = 50, MOD = 1e9+7;
long long n;
long long lcm[maxN], f[maxN], ans;

void calc(){
    cin >> n;
    ans = 0;
    lcm[1] = 1; f[1] = n;
    for(long long i=2; i<maxN; ++i){
        lcm[i] = lcm[i-1]*i/__gcd(lcm[i-1], i);
        f[i] = n/lcm[i];
        ans = (ans + (f[i-1] - f[i])*i) % MOD;
        if (lcm[i] > n) break;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--) calc();
    return 0;
}
