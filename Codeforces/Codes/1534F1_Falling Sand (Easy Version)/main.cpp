#include <bits/stdc++.h>
using namespace std;

const int maxN = 4e5+100;
int n, m, ans, cnt_lt, cnt, N1, N2;
int a[maxN], num[maxN], low[maxN], id[maxN], deg[maxN];
string c[maxN];
vector<int> d[maxN];
const int di[4]={-1, 0, 1, 0}, dj[4]={0, -1, 0, 1};
vector<int> e[maxN], e2[maxN];
set<int> Q;
vector<int> st;
//////

void enter(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> c[i];
        d[i] = vector<int>(m, 0);
    }
    for(int j=0; j<m; ++j) cin >> a[j];
}
//////

void dfs_lt(int i, int j){
    if (i<0 || j<0 || i>=n || j>=m) return;
    if (d[i][j] != 0 || c[i][j] != '#') return;
    d[i][j]=cnt_lt;
    for(int p=0; p<4; ++p) dfs_lt(i+di[p], j+dj[p]);
}

void make_graph(){
    cnt_lt = 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if (c[i][j]=='#' && d[i][j]==0) ++cnt_lt, dfs_lt(i, j);
    N1=cnt_lt;

    for(int j=0; j<m; ++j){
        int curi = -1;
        for(int i=0; i<n; ++i){
            bool left=false, right=false;
            if (c[i][j]=='#'){
                if (curi != -1 && d[i][j]!=d[curi][j]){
                    e[d[curi][j]].push_back(d[i][j]);
                    left = false; right = false;
                }
                curi = i;
            }
            if (!left && j>0 && c[i][j-1] == '#' && curi != -1){
                if (d[i][j-1] != d[curi][j]) e[d[curi][j]].push_back(d[i][j-1]);
                left = true;
            }
            if (!right && j+1<m && c[i][j+1] == '#' && curi != -1){
                if (d[i][j+1] != d[curi][j]) e[d[curi][j]].push_back(d[i][j+1]);
                right = true;
            }
        }
    }
}
//////

void tarjan(int u){
    num[u] = low[u] = ++cnt;
    st.push_back(u);
    for(int v: e[u]){
        if (id[v] != 0) continue;
        if (num[v] == 0){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }

    if (num[u] == low[u]){
        ++cnt_lt;
        while (true){
            int v = st.back(); st.pop_back();
            id[v] = cnt_lt;
            if (v == u) break;
        }
    }
}

void make_graph2(){
    cnt = cnt_lt = 0;
    for(int u=1; u<=N1; ++u) id[u] = num[u] = low[u] = 0;
    for(int u=1; u<=N1; ++u)
        if (num[u] == 0) tarjan(u);

    N2 = cnt_lt;
    for(int u=1; u<=N1; ++u)
        for(int v: e[u])
            if (id[u] != id[v]) e2[id[u]].push_back(id[v]);

}
//////

void solve(){
    for(int u=1; u<=N2; ++u)
        for(int v: e2[u]) ++deg[v];
    ans = 0;
    for(int u=1; u<=N2; ++u)
        if (deg[u] == 0) ++ans;
    cout << ans;
}
//////

int main()
{
    //freopen("a.inp", "r", stdin);
    enter();
    make_graph();
    make_graph2();
    solve();
    return 0;
}
