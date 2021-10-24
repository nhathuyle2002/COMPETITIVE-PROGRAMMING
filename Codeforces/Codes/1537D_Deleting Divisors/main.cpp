#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
void init(){
    int x=1;
    for(int i=1; i<=30; ++i){
        x*=2;
        mp[x]=i;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    int test; cin >> test;
    while (test--){
        int n; cin >> n;
        if (n%2 == 1){
            cout << "Bob\n";
            continue;
        }
        if (mp[n]%2 == 1){
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";
    }
}
