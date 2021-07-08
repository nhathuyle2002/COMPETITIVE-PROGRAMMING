#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int maxN = 1e6+10;
int n;
long long G[maxN], F[maxN], ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;

    F[0] = 0;
    for(int i=1; i<=n; ++i) G[i]=1;
    for(int i=1; i<n; ++i){
        for(int j=2*i; j<=n; j+=i)
            G[j] = (G[j]+1) % MOD;
    }

    long long temp = 0;
    for(int i=1; i<=n; ++i){
        F[i] = (G[i] + temp) % MOD;
        temp = (temp + F[i]) % MOD;
    }
    cout << F[n];
    return 0;
}
