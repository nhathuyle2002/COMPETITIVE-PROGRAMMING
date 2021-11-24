#include <bits/stdc++.h>
using namespace std;

const int maxS = 1e6+100;

int S, n, a[100];
int64_t f[maxS];
bool d[maxS];

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> S >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=n; i>=1; --i)
        if (d[a[i]] == true){
            swap(a[i], a[n]);
            --n;
        }
        else
            d[a[i]] = true;

    f[0] = 1;
    for(int i=1; i<=n; ++i)
        for(int j=a[i]; j<=S; ++j)
            f[j] += f[j - a[i]];
    cout << f[S];
}
