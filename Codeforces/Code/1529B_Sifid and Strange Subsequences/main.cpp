#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--){
        int n; cin >> n;
        vector<int> a;
        int ming = -1;
        for(int i=0; i<n; ++i){
            int x; cin >> x;
            if (x <= 0) a.push_back(x); else
            if (ming == -1) ming = x; else
            if (x < ming) ming = x;
        }
        if (ming == -1){
            cout << a.size() << '\n';
            continue;
        }
        int ming2 = 2e9+1;
        sort(a.begin(), a.end());
        for(int i=1; i<a.size(); ++i)
            if (a[i]-a[i-1] < ming2) ming2 = a[i]-a[i-1];
        if (ming2 >= ming) a.push_back(ming);
        cout << a.size() << '\n';
    }
    return 0;
}
