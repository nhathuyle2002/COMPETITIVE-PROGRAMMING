#include <bits/stdc++.h>
using namespace std;

bool compare(const int &x, const int &y){
    if ((x&1) != (y&1)) return (x&1) == 0;
    return x > y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), compare);
        //for(int x: a) cout << x << ' '; cout << '\n';
        int ans = 0;
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                if (__gcd(a[i], 2*a[j]) > 1) ++ans;
        cout << ans << '\n';
    }
}
