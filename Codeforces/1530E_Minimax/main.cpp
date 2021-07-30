#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 100;
int cnt[26], posa, ncnt, cnta, cntb, firstpos1;
string s;

void init(){
    for(int i=0; i<26; ++i) cnt[i] = 0;
    posa = ncnt = cnta = cntb = firstpos1 = 0;
    cin >> s;
    for(char &x: s) ++ cnt[x-'a'];

    for(int i=0; i<26; ++i) if (cnt[i] == 1){
        firstpos1 = i;
        break;
    }
    for(int i=0; i<26; ++i) if (cnt[i] > 0){
        posa = i;
        cnta = cnt[i];
        break;
    }
    for(int i=0; i<26; ++i) if (cnt[i] > 0){
        ++ ncnt;
        if (i != posa) cntb += cnt[i];
    }
}

void solve0(){
    cout << char(firstpos1 + 'a');
    -- cnt[firstpos1];
    for(int i=0; i<26; ++i) while (cnt[i] > 0){
        cout << char(i + 'a');
        -- cnt[i];
    }
    cout << '\n';
}

void solve1(){
    for(int i=0; i<26; ++i) while (cnt[i] > 0){
        cout << char(i + 'a');
        -- cnt[i];
    }
    cout << '\n';
}

void solve2(){
    cout << char(posa + 'a') << char(posa + 'a');
    cnt[posa] -= 2;
    int curi = posa+1;
    while (cnt[posa] > 0){
        while (cnt[curi] == 0) ++ curi;
        cout << char(curi + 'a') << char(posa + 'a');
        -- cnt[posa]; -- cnt[curi];
    }
    for(int i=curi; i<26; ++i) while (cnt[i] > 0){
        cout << char(i + 'a');
        -- cnt[i];
    }
    cout << '\n';
}

void solve3(){
    cout << char(posa + 'a');
    -- cnt[posa];
    for(int i=posa+1; i<26; ++i) while (cnt[i] > 0){
        cout << char(i + 'a');
        -- cnt[i];
    }
    while (cnt[posa] > 0){
        cout << char(posa + 'a');
        -- cnt[posa];
    }
    cout << '\n';
}

void solve4(){
    int posb = 0, posc = 0;
    for(int i=posa+1; i<26; ++i) if (cnt[i] > 0){
        posb = i;
        break;
    }
    for(int i=posb+1; i<26; ++i) if (cnt[i] > 0){
        posc = i;
        break;
    }
    cout << char(posa + 'a') << char(posb + 'a');
    -- cnt[posa]; -- cnt[posb];
    while (cnt[posa] > 0){
        cout << char(posa + 'a');
        -- cnt[posa];
    }
    cout << char(posc + 'a');
    -- cnt[posc];
    for(int i=posa+1; i<26; ++i) while (cnt[i] > 0){
        cout << char(i + 'a');
        -- cnt[i];
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test; cin >> test;
    while (test--){
        init();
        if (firstpos1 != 0) solve0();
        else if (cnta <= 2 || ncnt == 1) solve1();
        else if (cnta-2 <= cntb) solve2();
        else if (ncnt == 2) solve3();
        else solve4();
    }
    return 0;
}
