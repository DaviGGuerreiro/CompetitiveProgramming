#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, h; cin>>n>>h;
    int resposta = 0, aux;
    for(int i = 0; i<n; i++){
        cin>>aux;
        if(aux <= h) resposta++;
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}