#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        int n; cin >> n;
        int ans = 0;
        while (n > 0){
            ans = max(ans, n%10);
            n/=10;
        }
        cout << ans << '\n';
    }
    return 0;
}
