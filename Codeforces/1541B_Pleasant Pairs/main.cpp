#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 100;
int n, a[maxN], ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        for(int x=1; x<=2*n; ++x) a[x] = 0;
        for(int i=1; i<=n; ++i){
            int x; cin >> x;
            a[x] = i;
        }
        ans = 0;
        for(int x=1; x<sqrt(2*n); ++x)
        if (a[x] != 0)
        for(int y=x*(x+1); y<=2*n; y+=x){
            int z = y/x;
            if (a[z] != 0 && a[x] + a[z] == y) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
