#include <bits/stdc++.h>
using namespace std;
#define double long double

double c, m, p, v, ans;
long long W = 1e10;

void calc(double c, double m, double p, double v, double cur, int num){
    ans += cur * p / (c+m+p) * num;
    double pc = c, pm = m, pp = p, pcur = cur;
    if (c > 0){
        cur *= c / (c+m+p);
        double delta = v;
        if (c < v) delta = c;
        c -= delta;
        if (m > 0) m += delta/2, p += delta/2;
        else p += delta;
        calc(c, m, p, v, cur, num+1);
    }
    c = pc; m = pm; p = pp; cur = pcur;
    if (m > 0){
        cur *= m / (c+m+p);
        double delta = v;
        if (m < v) delta = m;
        m -= delta;
        if (c > 0) c += delta/2, p += delta/2;
        else p += delta;
        calc(c, m, p, v, cur, num+1);
    }
}

int main(){
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> c >> m >> p >> v;
        c*=W; m*=W; p*=W; v*=W;
        ans = 0;
        calc(c, m, p, v, 1, 1);
        cout << setprecision(12) << fixed << ans << '\n';
    }
    return 0;
}
