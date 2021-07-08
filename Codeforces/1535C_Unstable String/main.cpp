#include <bits/stdc++.h>
using namespace std;

const int maxN=2e5+100;
long long ans;
char s[maxN];
int n, pre[maxN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test; cin >> test;
    while (test--){
        cin >> s+1; n=strlen(s+1);
        s[0]='?'; pre[0] = 0;
        for(int i=1; i<=n; ++i)
            if (s[i] == '?') pre[i] = pre[i-1];
            else pre[i] = i;

        ans = 0;
        int left = 0;
        char pre_X = '?';
        for(int right=1; right<=n; ++right){
            if (pre_X == '?') pre_X = s[right];
            else{
                if (s[right] == pre_X){
                    left = pre[right-1];
                    pre_X = s[right];
                }
                else if (pre_X == '0') pre_X='1'; else pre_X='0';
            }
            ans += right-left;
        }
        cout << ans << '\n';
    }
}
