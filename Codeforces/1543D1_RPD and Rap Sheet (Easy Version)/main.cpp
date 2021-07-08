#include <bits/stdc++.h>
using namespace std;

int n, K;

int main(){
    //freopen("a.inp", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n >> K;
        int pre = 0;
        for(int i=0; i<=n; ++i){
            cout << (pre^i) << '\n';
            int c; cin >> c;
            if (c == 1) break;
            pre = i;
        }
    }
    return 0;
}
