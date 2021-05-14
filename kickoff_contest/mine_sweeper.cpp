#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[50][50], b[50][50];

int value(int i, int j){
    return a[i][j]-(b[i][j-1]==1)-(b[i-1][j]==1)-(b[i+1][j]==1)-(b[i][j+1]==1);
}

void check(int i, int j){
    if (i>n){
        bool ok=true;
        for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if (value(i, j)!=0) ok=false;
        if (ok){
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j) cout << b[i][j] << ' ';
                cout << '\n';
            }
            exit(0);
        }
        return;
    }

    if (b[i][j]!=-1){
        check(i+j/m, j%m+1);
        return;
    }
    if (i==1 || value(i-1, j)==0){
        b[i][j]=0;
        check(i+j/m, j%m+1);
    }
    if (i==1 || value(i-1, j)==1){
        b[i][j]=1;
        check(i+j/m, j%m+1);
    }
    b[i][j]=-1;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) cin >> a[i][j], b[i][j]=-1;

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if (a[i][j]==0){
                b[i-1][j]=b[i][j-1]=b[i+1][j]=b[i][j+1]=0;
            } else
            if (a[i][j]==4){
                b[i-1][j]=b[i][j-1]=b[i+1][j]=b[i][j+1]=1;
            }

    check(1, 1);

    return 0;
}
