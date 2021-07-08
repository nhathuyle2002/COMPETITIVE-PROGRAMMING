#include <bits/stdc++.h>
//#pragma GCC optimize ("O2, unroll-loops")
//#pragma GCC optimize ("no-stack-protector, fast-math")
using namespace std;

const int maxN = 3e5+100;
int n;
vector<int> e1[maxN], e2[maxN];
int st[maxN], fi[maxN], cnt_time, answer;

struct compare1{
    bool operator() (const int &u, const int &v) const{
        return st[u] > st[v];
    }
};
set<int, compare1> S;

void dfs_time(int u){
    st[u] = ++cnt_time;
    for(int v: e2[u]) dfs_time(v);
    fi[u] = cnt_time;
}

void dfs_ans(int u){
    auto it = S.lower_bound(u);
    int ancestor = -1;
    if (it != S.end() && fi[u] <= fi[*it]){
        ancestor = *it;
        S.erase(it);
    }
    S.insert(u);
    if (answer < S.size()) answer = S.size();
    for(int v: e1[u]) dfs_ans(v);

    S.erase(u);
    if (ancestor != -1) S.insert(ancestor);
}


int main(){
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int testcase; cin >> testcase;
    while (testcase--){
        cin >> n;
        for(int u=1; u<=n; ++u) e1[u].clear(), e2[u].clear();

        int pa;
        for(int u=2; u<=n; ++u) cin >> pa, e1[pa].push_back(u);
        for(int u=2; u<=n; ++u) cin >> pa, e2[pa].push_back(u);

        cnt_time = 0;
        dfs_time(1);

        S.clear();
        answer = 0;
        dfs_ans(1);
        cout << answer << '\n';
    }
}
