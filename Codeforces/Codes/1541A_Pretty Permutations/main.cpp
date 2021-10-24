#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> n;
        if (n%2 == 0){
            for(int i=1; i<=n; i+=2) cout << i+1 << ' ' << i << ' ';
        }
        else{
            cout << "3 1 2 ";
            for(int i=4; i<=n; i+=2) cout << i+1 << ' ' << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
