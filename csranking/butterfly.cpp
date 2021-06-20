#include <bits/stdc++.h>
using namespace std;

set<int> a;
long long ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x;
    while (cin >> x) a.insert(x+1);
    ans = 0;
    for(int x: a) ans += x;
    cout << ans;
    return 0;
}
