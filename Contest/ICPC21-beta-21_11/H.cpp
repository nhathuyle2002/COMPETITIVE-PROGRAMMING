#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+100;
const int64_t MOD = 1e9+13;
const int64_t base = 311;

int n, m, d;
map<int64_t, int> mp;

int64_t getHash(){
    int64_t ans = 0;
    int temp;
    for (int i=1; i<=d+1; ++i){
        cin >> temp;
        ans = ans * base + temp;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> d;
    for (int i=1; i<=n; ++i) ++mp[getHash()];
    for (int i=1; i<=m; ++i)
        if (mp[getHash()] == 0) cout << "GOOD\n"; else cout << "BAD\n";
    return 0;
}
