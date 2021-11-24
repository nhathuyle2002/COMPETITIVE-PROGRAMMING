#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+100;
int n, m, K, source, target;
map<string, int> mp;

struct DataEdge{
    int x, y, w;
};
vector<DataEdge> edge;
vector<int> e[maxN];

struct Node{
    int stone, influ, totalInflu;
} node[maxN];

void enter(){
    cin >> n >> m >> K;

    string strS, strT;
    cin >> strS >> strT;
    for(int u=1; u<=n; ++u){
        string temp; cin >> temp;
        mp[temp] = u;
        cin >> node[u].stone >> node[u].influ;
    }

    source = mp[strS]; target = mp[strT];

    for(int i=0; i<m; ++i){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        int u = mp[temp1], v = mp[temp2], c;
        cin >> c;
        e[u].push_back(edge.size()); edge.push_back({u, v, c});
        e[v].push_back(edge.size()); edge.push_back({v, u, c});
    }
}

int bfs[maxN];
void calcInflu(int S){
    deque<int> dq;
    for(int u=1; u<=n; ++u) bfs[u] = -1;
    bfs[S] = 0;
    dq.push_back(S);

    while (!dq.empty()){
        int u = dq.front(); dq.pop_front();
        for (int id: e[u]){
            int v = edge[id].y;
            if (bfs[v] != -1) continue;
            bfs[v] = bfs[u] + 1;
            if (bfs[u] <= K-1){
                node[S].totalInflu += node[v].influ;
                if (bfs[u] < K-1) dq.push_back(v);
            }
        }
    }
}

const int oo = 1e9;
typedef pair<int, int> pii;
int d[maxN], dS[maxN];
void dijkstra(int S, int T){
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    for(int u=1; u<=n; ++u){
        d[u] = oo;
        dS[u] = 0;
    }
    d[S] = 0; dS[S] = node[S].stone;
    Q.push({d[S], S});

    while (!Q.empty()){
        int du = Q.top().first, u = Q.top().second; Q.pop();
        if (du != d[u]) continue;
        for(int id: e[u]){
            int v = edge[id].y, c = edge[id].w + node[u].totalInflu;
            if (d[u] + c < d[v]){
                d[v] = d[u] + c;
                dS[v] = dS[u] + node[v].stone;
                Q.push({d[v], v});
            }
            else if (d[u] + c == d[v] && dS[u] + node[v].stone > dS[v]){
                dS[v] = dS[u] + node[v].stone;
            }
        }
    }
}

void solve(){
    for(int u=1; u<=n; ++u) calcInflu(u);
    dijkstra(source, target);
    cout << d[target] << ' ' << dS[target];
}

int main()
{
    enter();
    solve();
    return 0;
}
