#include <bits/stdc++.h>
using namespace std;

int n, m, Q;
typedef long long LL;
const LL base=27;
set<LL> S[11];
vector<LL> POW(11);
char s[100010];

int main()
{
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> Q;
    vector<vector<int> > a(n+1, vector<int>(m+1));

    for(int i=1; i<=n; ++i){
        cin >> (s+1);
        for(int j=1; j<=m; ++j) a[i][j]=s[j]-'a';
    }

    POW[0]=1;
    for(int i=1; i<=10; ++i) POW[i]=POW[i-1]*base;

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j){
        LL H=0;
        for(int k=j; k<=min(m, j+9); ++k){
            H=H*base+a[i][k];
            S[k-j+1].insert(H);
        }
    }

    for(int j=1; j<=m; ++j)
    for(int i=1; i<=n; ++i){
        LL H=0;
        for(int k=i; k<=min(n, i+9); ++k){
            H=H*base+a[k][j];
            S[k-i+1].insert(H);
        }
    }

    while (Q--){
        cin >> (s+1);
        LL Hs=0;
        int ns=strlen(s+1);
        for(int i=1; i<=ns; ++i)
            Hs=Hs*base+s[i]-'a';
        if (S[ns].find(Hs)!=S[ns].end()) cout << 1; else cout << 0;
    }

    return 0;
}
