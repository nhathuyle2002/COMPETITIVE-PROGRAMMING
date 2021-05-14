#include <bits/stdc++.h>
using namespace std;

int n, S;
const int maxN=15000;
bool d[110][2*maxN+1];
int ans[110];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> S;

    d[0][maxN]=true;
    for(int i=1; i<=n; ++i)
        for(int x=0; x<=2*maxN; ++x)
            if (x>=i && d[i-1][x-i]) d[i][x]=true;
            else if (x+i<=2*maxN && d[i-1][x+i]) d[i][x]=true;

    if (!d[n][S+maxN]) cout << "NO_SOLUTION"; else{
        int x=S+maxN;
        for(int i=n; i>0; --i)
            if (x>=i && d[i-1][x-i]){
                ans[i]=1;
                x-=i;
            }
            else{
                ans[i]=-1;
                x+=i;
            }
        for(int i=1; i<=n; ++i)
            if (ans[i]==-1) cout << '-'; else cout << '+';
    }

    return 0;
}
