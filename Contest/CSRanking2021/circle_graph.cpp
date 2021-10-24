#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int maxN = 2e5+100;
const ld PI = atan(1)*4;
struct point{
    ld x, y;
};
int n, same0 = 0, ans;
point a[maxN];
ld b[maxN];
ld K;

void enter(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    cin >> K;
    cin >> a[0].x >> a[0].y;
    for(int i=1; i<=n; ++i) a[i].x -= a[0].x, a[i].y -= a[0].y;
    for(int i=n; i>=1; --i)
    if (a[i].x == 0 && a[i].y == 0){
        ++same0;
        swap(a[i], a[n]);
        --n;
    }
}

void init(){
    for(int i=1; i<=n; ++i){
        //if (a[i].x == 0 && a[i].y == 0){} khong co
        if (a[i].x == 0){
            if (a[i].y > 0) b[i] = 90; else b[i] = 270;
        } else
        if (a[i].x != 0){
            b[i] = atan(a[i].y/a[i].x) *180/PI;
            if (b[i] < 0) b[i] += 360;
            if (a[i].x < 0) b[i] += 180;
            if (b[i] > 360) b[i] -= 360;
        }
        //cerr << b[i] << ' ';
    }
    for(int i=n+1; i<=2*n; ++i)
        b[i] = b[i-n] + 360;
}

void solve(){
    sort(b+1, b+2*n+1);
    ans = 0;
    int j=1;
    for(int i=1; i<=n; ++i){
        while (j<i+n && b[j]-b[i] <= K) ++j;
        ans = max(ans, j-i);
    }
    cout << ans + same0;
}

int main()
{
    //freopen("a.txt", "r", stdin);
    enter();
    init();
    solve();
    return 0;
}
