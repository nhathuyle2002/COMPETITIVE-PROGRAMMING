#include <bits/stdc++.h>
using namespace std;

const int maxN=510;
int n, K, ans;
int d[maxN], trace[maxN], bit[maxN];
vector<int> query[maxN];
//////

void BFS(){
    for(int i=0; i<=n; ++i) d[i] = -1;
    d[0] = 0;
    deque<int> q; q.push_back(0);
    while (!q.empty()){
        int i = q.front(); q.pop_front();
        for(int x=0; x<=min(i, K); ++x){
            int y = K-x, j = i-x+y;
            if (y<=n-i && j>=0 && j<=n && d[j]==-1){
                d[j] = d[i]+1;
                trace[j] = i;
                q.push_back(j);
            }
        }
    }
}

void solve(){
    vector<int> q;
    int i = n;
    while (i>0){
        q.push_back(i);
        i = trace[i];
    }
    for(int i=1; i<=n; ++i) bit[i]=0;
    int ci = 0, step = 0;
    while (!q.empty()){
        int cj = q.back(); q.pop_back();
        int x = (K-cj+ci)/2, y = (K+cj-ci)/2;
        vector<int> vex;
        for(int i=1; i<=n; ++i){
            if (x>0 && bit[i] == 1){
                vex.push_back(i);
                --x;
            }
            if (y>0 && bit[i] == 0){
                vex.push_back(i);
                --y;
            }
        }
        for(int i: vex) bit[i] = 1-bit[i];
        ci = cj;
        query[++step]=vex;
    }
}

void print_answer(){
    /*cout << d[n] << '\n';
    for(int i=1; i<=d[n]; ++i){
        for(int u: query[i]) cout << u << ' ';
        cout << '\n';
    }*/
    ans = 0;
    for(int i=1; i<=d[n]; ++i){
        cout << '?';
        for(int u: query[i]) cout << ' ' << u;
        cout << '\n';
        int x; cin >> x;
        ans ^= x;
    }
    cout << "! " << ans;
}

int main(){
    cin >> n >> K;
    BFS();
    if (d[n] == -1){
        cout << "-1\n";
        return 0;
    }
    solve();
    print_answer();
    return 0;
}
