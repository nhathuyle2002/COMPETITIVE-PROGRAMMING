#include <bits/stdc++.h>
using namespace std;

const int maxN = 2010, oo=1e5;
int test, n;
bool a[maxN][maxN], b[maxN][maxN];

void swap_cot(int x, int y){
    for(int i=1; i<=n; ++i) swap(a[i][x], a[i][y]);
}
void swap_hang(int x, int y){
    for(int i=1; i<=n; ++i) swap(a[x][i], a[y][i]);
}

int convert(bool fi){
    if (fi == false)
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) a[i][j] = b[i][j];
    int dem = 0;
    bool cur = fi;
    for(int i=1; i<=n; ++i){
        if (a[i][1] != cur){
            bool ok = false;
            for(int i2=i+1; i2<=n; ++i2)
                if (a[i2][1] == cur){
                    swap_hang(i, i2);
                    ++dem;
                    ok = true;
                    break;
                }
            if (!ok) return oo;
        }
        cur = !cur;
    }

    cur = fi;
    for(int i=1; i<=n; ++i){
        if (a[1][i] != cur){
            bool ok = false;
            for(int i2=i+1; i2<=n; ++i2)
                if (a[1][i2] == cur){
                    swap_cot(i, i2);
                    ++dem;
                    ok = true;
                    break;
                }
            if (!ok) return oo;
        }
        cur = !cur;
    }

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j){
        if (i>1 && a[i-1][j] == a[i][j]) return oo;
        if (j>1 && a[i][j-1] == a[i][j]) return oo;
    }
    return dem;
}

int main()
{
    //freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> test;
    for(int t=1; t<=test; ++t){
        cin >> n; n*=2;
        string s;
        for(int i=1; i<=n; ++i){
            cin >> s;
            for(int j=1; j<=n; ++j) b[i][j]=a[i][j]=s[j-1]-'0';
        }
        int ans = min(convert(0), convert(1));
        if (ans == oo) ans = -1;
        cout << "Case " << t << ": " << ans << '\n';
    }
    return 0;
}
