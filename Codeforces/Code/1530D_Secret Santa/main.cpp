#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 100;
int n, a[maxN], ans[maxN], res;
vector<int> e[maxN];
bool d[maxN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n; res = 0;
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int i=1; i<=n; ++i) cin >> a[i], e[a[i]].push_back(i);
        for(int i=1; i<=n; ++i) d[i] = true;
        for(int i=1; i<=n; ++i) if (!e[i].empty()){
            ++ res;
            ans[e[i][0]] = i; d[i] = false;
        }
        int curx = 1;
        for(int i=1; i<=n; ++i) if (e[i].size() > 1){
            for(int j=1; j<e[i].size(); ++j){
                while (!d[curx]) ++curx;
                ans[e[i][j]] = curx; d[curx] = false;
                if (e[i][j] == curx) swap(ans[e[i][j]], ans[e[i][j-1]]);
            }
        }
        cout << res << '\n';
        for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
