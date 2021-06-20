#include <bits/stdc++.h>
using namespace std;

bool songuyen(string s){
    if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
    if (s.size() == 0) return false;
    for(char x: s)
        if (x < '0' || x > '9') return false;
    return true;
}

bool sothapphan(string s){
    if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
    if (s.size() == 0) return false;
    int dem = 0;
    for(char x: s)
        if (x == '.'){
            ++dem;
            if (dem > 1) return false;
        } else
        if (x < '0' || x > '9') return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    bool ok = false;
    if (songuyen(s) || sothapphan(s)) ok = true;
    for(int i=0; i<s.size(); ++i){
        if (s[i] == 'e'){
            if (sothapphan(s.substr(0, i)) && songuyen(s.substr(i+1, s.size()-i-1))) ok = true;
        }
    }
    if (ok) cout << "True"; else cout << "False";
    return 0;
}
