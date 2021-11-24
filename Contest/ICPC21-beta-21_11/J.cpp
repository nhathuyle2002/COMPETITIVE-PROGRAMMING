#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+100;
int n, P[maxN], Q[maxN], res;

int calc(int i, int key1, int key2 = -1){
    while (i <= n && (P[i] == key1 || Q[i] == key1 || P[i] == key2 || Q[i] == key2)) ++i;
    return i;
}

void solve(){
    res = 0;
    int i = 1;
    while (i <= n){
        int nex1[2] = {calc(i, P[i]), calc(i, Q[i])};
        int nex2[4] = {calc(nex1[0], P[i], P[nex1[0]]), calc(nex1[0], P[i], Q[nex1[0]]), calc(nex1[1], Q[i], P[nex1[1]]), calc(nex1[1], Q[i], Q[nex1[1]])};

        for(int id=0; id<4; ++id)
            if (nex2[id] > i) i = nex2[id];
        ++ res;
    }
    cout << res;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> P[i] >> Q[i];
    solve();
    return 0;
}
