#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+100;
int n;
vector<int> e[maxN];
long long W[maxN][2], F[maxN][2];
bool avail[maxN];

void dfs(int u){
    avail[u] = false;
    F[u][0] = F[u][1] = 0;
    for(int &v: e[u])
    if (avail[v]){
        dfs(v);
        for(int k1=0; k1<2; ++k1)
            F[u][k1] += max(F[v][0]+abs(W[u][k1]-W[v][0]), F[v][1]+abs(W[u][k1]-W[v][1]));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int i=0; i<=n; ++i) e[i].clear();
        for(int i=1; i<=n; ++i) cin >> W[i][0] >> W[i][1];
        for(int i=0; i<n-1; ++i){
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1; i<=n; ++i) avail[i] = true;
        dfs(1);
        cout << max(F[1][0], F[1][1]) << '\n';
    }
    return 0;
}
