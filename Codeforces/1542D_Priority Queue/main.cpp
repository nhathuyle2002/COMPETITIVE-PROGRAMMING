#include <bits/stdc++.h>
using namespace std;

const int maxN = 510;
const long long MOD = 998244353;
int n, a[maxN], pos[maxN];
char type[maxN];
bool done[maxN];
long long f[maxN][maxN], res;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> type[i];
        if (type[i] == '+') cin >> a[i]; else a[i] = -1;
        pos[i] = i;
    }
    sort(pos+1, pos+n+1, [](int x, int y){return a[x] < a[y];});

    res = 0;
    for(int i=1; i<=n; ++i) done[i] = false;
    for(int s=1; s<=n; ++s) if (a[pos[s]] != -1){
        f[0][0] = 1;
        for(int i=1; i<=n; ++i){
            if (a[i] == -1){
                f[i][0] = (f[i-1][0]*2 + f[i-1][1]) % MOD;
                for(int j=1; j<=n; ++j) f[i][j] = (f[i-1][j] + f[i-1][j+1]) % MOD;
            }
            else if (pos[s] == i){
                f[i][0] = 0;
                for(int j=1; j<=n; ++j) f[i][j] = f[i-1][j-1];
            }
            else if (done[i]){
                f[i][0] = f[i-1][0];
                for(int j=1; j<=n; ++j) f[i][j] = (f[i-1][j] + f[i-1][j-1]) % MOD;
            }
            else for(int j=0; j<=n; ++j) f[i][j] = f[i-1][j]*2 % MOD;

            if (i >= pos[s]) f[i][0] = 0;
        }
        done[pos[s]] = true;
        for(int j=0; j<=n; ++j) res = (res + f[n][j]*a[pos[s]]) % MOD;
    }

    cout << res;
    return 0;
}
