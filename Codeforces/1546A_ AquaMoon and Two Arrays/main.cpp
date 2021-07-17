#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;
int n, a[maxN], b[maxN];
vector<pair<int, int> > d;
vector<int> pl, pg;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        int sum = 0;
        for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
        for(int i=1; i<=n; ++i) cin >> b[i], sum -= b[i];
        if (sum != 0){
            cout << -1 << '\n';
            continue;
        }
        d.clear(); pl.clear(); pg.clear();
        for(int i=1; i<=n; ++i)
            if (a[i] < b[i]) pl.push_back(i);
            else if (a[i] > b[i]) pg.push_back(i);

        while (!pl.empty()){
            int i = pg.back(); pg.pop_back();
            int j = pl.back(); pl.pop_back();
            d.push_back({i, j});
            --a[i]; ++a[j];
            if (a[i] > b[i]) pg.push_back(i);
            if (a[j] < b[j]) pl.push_back(j);
        }
        cout << d.size() << '\n';
        for(pair<int, int> &p: d) cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
