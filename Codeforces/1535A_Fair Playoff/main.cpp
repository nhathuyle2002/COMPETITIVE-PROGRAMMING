#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        pair<int, int> a[4];
        for(int i=0; i<4; ++i)
            cin >> a[i].first, a[i].second = i;
        sort(a, a+4, greater<pair<int, int> > ());
        if (a[0].second >> 1 != a[1].second >> 1) cout << "YES\n"; else cout << "NO\n";
    }
}
