#include <bits/stdc++.h>
using namespace std;

const int maxN=110, maxS=2000*100+10;
int n, a[maxN];
bool d[maxN][2*maxS+1];

bool check(int i0){
    for(int j=0; j<=2*maxS; ++j) d[0][j]=false;
    d[0][maxS]=true;
    for(int i=1; i<=n; ++i)
    if (i!=i0){
        for(int j=0; j<=2*maxS; ++j)
            if (j>=a[i] && d[i-1][j-a[i]]) d[i][j]=true;
            else if (j+a[i]<=2*maxS && d[i-1][j+a[i]]) d[i][j]=true;
            else d[i][j]=false;
    } else{
        for(int j=0; j<=2*maxS; ++j)
            d[i][j]=d[i-1][j];
    }
    if (d[n][maxS]) return true; else return false;
}


int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    if (!check(0)) cout << 0;
    else{
        for(int i=1; i<=n; ++i)
        if (!check(i)){
            cout << "1\n" << i;
            break;
        }
    }
    return 0;
}
