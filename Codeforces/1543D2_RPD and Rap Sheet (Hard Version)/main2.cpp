#include <bits/stdc++.h>
using namespace std;

int n, K;

int congXor(int a, int b){
    int ans = 0, base = 1;
    while (a > 0 || b > 0){
        int c = a % K, d = b % K;
        a/=K; b/=K;
        int e = (c + d) % K;
        ans += base * e;
        base *= K;
    }
    return ans;
}

int truXor(int a, int b){
    int ans = 0, base = 1;
    while (a > 0 || b > 0){
        int c = a % K, d = b % K;
        a/=K; b/=K;
        int e = (c - d + K) % K;
        ans += base * e;
        base *= K;
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while (t--) {
        cin >> n >> K;
        for(int i=0; i<n; ++i) {
            if  (i == 0) cout << 0; else
            if (i & 1) cout << truXor(i-1, i);
            else cout << truXor(i, i-1);
            cout << '\n';
            int c; cin >> c;
            if (c == 1) break;
        }
    }
    return 0;
}
