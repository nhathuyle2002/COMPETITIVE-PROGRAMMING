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
    int t, ans; cin >> t;
    while (t--) {
        cin >> n >> K;
        int w = 0;
        for(int i=0; i<n; ++i) {
            if (i == 0) w = 0; else w = truXor(i, i-1);
            cout << w << '\n';
            cin >> ans;
            if (ans) break;
            ++i;
            w = truXor(i-1, i);
            cout << w << '\n';
            cin >> ans;
            if (ans) break;
        }
    }
    return 0;
}
