#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 100;
int n;
char res[maxN];

void res26(){
    for(int i=1; i<=n; ++i) res[i] = i-1 + 'a';
}

void solve(){
    int del = (n-10)/2, first = del + 2, last = n - del;
    for(int i=1; i<first; ++i) res[i] = 'a';
    for(int i=last+1; i<=n; ++i) res[i] = 'a';
    for(int i=first; i<=last; ++i) res[i] = i-first+1 + 'a';
}

bool check(){
    for(int len=1; len<n; ++len)
    for(int i=1; i<=n-len+1; ++i){
        int cnt = 0;
        for(int j=1; j<=n-len+1; ++j){
            bool ok = true;
            for(int k=0; k<len; ++k)
            if (res[i+k] != res[j+k]){
                ok = false;
                break;
            }
            if (ok) ++cnt;
        }
        if (cnt % 2 == 0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        if (n <= 26) res26();
        else solve();
        for(int i=1; i<=n; ++i) cout << res[i];
        cout << '\n';
        //if (check()) cout << n << ' ' << "True\n"; else cout << n << ' ' << "False\n";
    }
    return 0;
}
