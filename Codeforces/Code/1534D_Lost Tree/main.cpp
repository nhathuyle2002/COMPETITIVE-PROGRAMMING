#include <bits/stdc++.h>
using namespace std;

const int maxN=2010;
int n;
typedef pair<int, int> pii;
set<pii> ans;
int d[maxN];

void addSet(int x, int y){
    if (x<y) ans.insert({x, y}); else ans.insert({y, x});
}

void calc(int u){
    cout << "? " << u << '\n';
    for(int i=1; i<=n; ++i) cin >> d[i];
}

int main(){
    cin >> n;
    calc(1);
    vector<int> s[2];
    for(int u=2; u<=n; ++u) {
        s[d[u]&1].push_back(u);
        if (d[u] == 1) addSet(1, u);
    }

    if (s[0].size() > s[1].size()) swap(s[0], s[1]);
    for(int u: s[0]){
        calc(u);
        for(int v=1; v<=n; ++v)
        if (d[v]==1) addSet(u, v);
    }

    cout << "!\n";
    for(pii p: ans) cout << p.first << ' ' << p.second << '\n';
}
