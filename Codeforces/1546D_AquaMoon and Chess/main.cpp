#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
const long long MOD = 998244353;

long long gt[maxN];
void init_gt(){
    gt[0] = 1;
    for(int i=1; i<maxN; ++i) gt[i] = gt[i-1] * i % MOD;
}

long long power(long long a, long long b){
    if (b == 0) return 1;
    long long c = power(a, b/2);
    c = c*c % MOD;
    if (b % 2 == 1) c = c*a % MOD;
    return c;
}

int main(){
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init_gt();
    int test; cin >> test;
    while (test--){
        int n; cin >> n;
        string s; cin >> s;
        int le = 0, cap = 0;
        for(int i=1; i<s.size(); ++i)
            if (s[i] == '1' && s[i-1] == '1'){
                ++ cap;
                s[i] = s[i-1] = '0';
            }
        for(int i=0; i<s.size(); ++i)
            if (s[i] == '1') ++ le;

        /// Tinh (n - cap - le) C (cap);
        n = n - cap - le;
        int k = cap;
        long long res = gt[n] * power(gt[k]*gt[n-k] % MOD, MOD-2) % MOD;
        cout << res << '\n';
    }
    return 0;
}
