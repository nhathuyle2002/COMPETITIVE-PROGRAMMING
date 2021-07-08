#include <bits/stdc++.h>
//#pragma GCC optimize ("O2, unroll-loops")
//#pragma GCC optimize ("no-stack-protector, fast-math")
using namespace std;

const int maxN =100;
int n, m;
char a[maxN][maxN];
bool d[maxN][maxN];

char nexx(char x){
    if (x=='R') return 'W'; else return 'R';
}

bool dfs(int i, int j, char x){
    if (i<1 || j<1 || i>n || j>m || !d[i][j]) return true;
    d[i][j]=false;
    if (a[i][j] == '.') a[i][j] = x;
    else if (a[i][j] != x)
        return false;
    char x2=nexx(x);
    return dfs(i-1, j, x2) && dfs(i, j-1, x2) && dfs(i+1, j, x2) && dfs(i, j+1, x2);
}

void dfs(int i, int j);

int main()
{
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n >> m;
        for(int i=1; i<=n; ++i) cin >> (a[i]+1);
        int bi=1, bj=1;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                d[i][j]=true;
                if (a[i][j] != '.') bi=i, bj=j;
            }
        char x = a[bi][bj];
        if (x=='.') x='R';
        if (!dfs(bi, bj, x)) cout << "NO\n"; else{
            cout << "YES\n";
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j)
                    cout << a[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}
