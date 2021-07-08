#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        long long a, b; cin >> a >> b;
        if (a == b){
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        if (a > b) swap(a, b);
        long long ans = b - a;
        long long c = a / ans;
        long long d = min(a-c*ans, (c+1)*ans-a);
        cout << ans << ' ' << d << '\n';
    }
    return 0;
}
