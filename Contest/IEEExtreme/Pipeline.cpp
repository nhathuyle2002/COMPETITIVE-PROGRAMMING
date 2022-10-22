#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=100;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

string s[N][N];
int num[N][N][N];
vector<int> e[1000000];
vector<int> p1, p2;
int n, m, d;
int deg[1000000];

void addedge(int l1, int r1, int c1, int l2, int r2, int c2) {
    if (min({l1, r1, c1, l2, r2, c2}) < 0)
        return;
    if (max(l1, l2) >= d)
        return;
    if (max(r1, r2) >= n)
        return;
    if (max(c1, c2) >= m)
        return;
    // cout << l1 << r1 << c1 << " " << l2 << r2 << c2 <<"\n";
    // return;
    int u = num[l1][r1][c1];
    int v = num[l2][r2][c2];
    for (int i = 1; i <= deg[u]; i++)
        for (int j = 1; j <= deg[v]; j++) {
            e[u + i].push_back(v + j);
            // e[v + j].push_back(u + i);
            // cout << u+i << " " << v + j <<'\n';
        }
}

vector<bool> visited;
vector<int> match;

bool DFS(int u) {
    for(int v: e[u])
    if ((!visited[v])) {
        visited[v] = true;

        if (match[v] == -1 || DFS(match[v])) {
            match[v] = u;
            return true;
        }
    }

    return false;
}

void solve(int nedge) {
    visited.clear();
    match.clear();
    int n = p1.size(), m = p2.size();
    if (n != m || n == 0) {
        cout << "NO\n";
        return;
    }
    int max_matching = 0;
    int cnt = -1;
    for(int i = 0; i < m; ++i) cnt = max(cnt, p2[i]);

    for (int i = 1; i <= nedge; i++)
        if (e[i].size() == 0) {
            cout << "NO\n";
            return;
        }

    vector<int> tmp; 
    for(int i = n - 1; i >= 0; --i) tmp.push_back(p1[i]);

    visited.assign(cnt + 1, false);
    match.assign(cnt + 1, -1);


    while (true) {
        bool stop = true;

        for(int i = 0; i <= cnt; ++i) visited[i] = false;

        for(int i = tmp.size() - 1; i >= 0; --i) 
        if (DFS(tmp[i])) {
            swap(tmp[i], tmp.back());
            tmp.pop_back();
            stop = false;
            ++max_matching;
        }

        if (stop) break;
    }

    if (max_matching == p1.size()) {
        cout << "YES\n";
    }
    else 
        cout << "NO\n";
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        int sumdeg = 0;
        cin >> n >> m >> d;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < n; j++) {
                cin >> s[i][j];
                for (int k = 0; k < m; k++) { 
                    num[i][j][k] = cnt;
                    if (s[i][j][k] == '*') 
                        deg[cnt] = 3;
                    else if (s[i][j][k] == '#')
                        deg[cnt] = 0;
                    else 
                        deg[cnt] = 2;
                    sumdeg += deg[cnt];
                    cnt += deg[cnt];
                    for (int id = 1; id <= deg[num[i][j][k]]; id++)
                        if ((i + j + k) % 2)
                            p1.push_back(num[i][j][k] + id);
                        else 
                            p2.push_back(num[i][j][k] + id);
                    // cout << i << j << k << " " << num[i][j][k] << " " << deg[num[i][j][k]] << "\n";
                }
            }
        // for (auto x:p1)
        //     cout << x << " ";
        // return 0;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < n; j++) 
                for (int k = 0; k < m; k++) {
                    int layer = i;
                    int nrow = j;
                    int ncol = k;
                    for (int nlayer = -1; nlayer <= 1; nlayer++)
                        for (int nnrow = -1; nnrow <= 1; nnrow++)
                            for (int nncol = -1; nncol <= 1; nncol++)
                                if (nlayer*nlayer + nnrow*nnrow + nncol*nncol == 1) {
                                    addedge(layer, nrow, ncol, layer + nlayer,nrow + nnrow,ncol + nncol);
                                }
                        
                }
        if (sumdeg %2) {
            cout << "NO\n";
        } else
            solve(cnt);
        p1.clear();
        p2.clear();
        for (int i = 0; i <= 50; i++)
            for (int j = 0; j <= 50; j++)
                for (int k = 0; k <= 50; k++)
                    num[i][j][k] = 0;

        for (int i = 0; i <= 500000; i++) {
            deg[i] = 0;
            e[i].clear();
        }
    }
}