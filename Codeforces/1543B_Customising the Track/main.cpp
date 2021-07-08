#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        long long sum = 0;
        for(int i=1; i<=n; ++i){
            int x; cin >> x;
            sum += x;
        }
        long long ans = (sum % n) * (n - sum % n);
        cout << ans << '\n';
    }
    return 0;
}
