#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        int n, m; cin >> n >> m;
        vector<vector<bool> > a(n, vector<bool>(m, false));
        a[0][0] = true;
        for(int i=1; i<n; ++i) if (a[i-1][0] == false) a[i][0] = true;
        for(int j=1; j<m; ++j) if (a[0][j-1] == false) a[0][j] = true;
        for(int j=1; j<m; ++j) if (a[n-1][j-1] == false && a[n-2][j-1] == false) a[n-1][j] = true;
        for(int i=1; i<n; ++i) if (a[i-1][m-1] == false && a[i][m-2] == false && a[i-1][m-2] == false && a[min(n-1,i+1)][m-2] == false && a[min(n-1,i+1)][m-1] == false) a[i][m-1] = true;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                if (a[i][j] == false) cout << 0; else cout << 1;
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
