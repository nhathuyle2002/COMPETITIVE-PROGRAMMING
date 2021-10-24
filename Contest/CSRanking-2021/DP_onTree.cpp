#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[2006];
llong dp[2006][2006], tmp[2006];
int a[2006], nChild[2006];
int n, k;

void DFS(int u) {
    nChild[u] = 1;
    dp[u][1] = 0, dp[u][0] = a[u];

    for(int v: V[u]) {
        DFS(v);

        for(int i = 1; i <= min(k, nChild[u] + nChild[v]); ++i) tmp[i] = 1e15;

        for(int i = 1; i <= min(k, nChild[u]); ++i)
        for(int j = 0; j <= nChild[v] && i + j <= k; ++j)
            tmp[i+j] = min(tmp[i+j], dp[u][i] + dp[v][j]);

        nChild[u] += nChild[v];
        for(int i = 1; i <= min(k, nChild[u]); ++i) dp[u][i] = tmp[i];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        for(int i = 0; i <= n; ++i) {
            nChild[i] = 0; V[i].clear();
            for(int j = 0; j <= k; ++j) dp[i][j] = 0;
        }

        for(int v = 2; v <= n; ++v) {
            int u; cin >> u >> a[v];
            V[u].push_back(v);
        }


        DFS(1);

        cout << dp[1][k] << '\n';
    }

    return 0;
}
