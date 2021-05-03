#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n+1, vector<int>(m+1));

    int ans=1e9;

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j){
        cin >> a[i][j];
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        if (i>=3 && j>=3) ans=min(ans, a[i][j]-a[i-3][j]-a[i][j-3]+a[i-3][j-3]);
    }

    cout << ans;

    return 0;
}
