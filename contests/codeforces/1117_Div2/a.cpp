#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, m; cin>>n>>m;
    map<char, bool> mapa; 
    string aux;
    ll resposta = true;
    for(int i = 0 ; i < n; i++){
        cin>>aux;
        mapa[aux[0] - 32] = true;
    }
    for(int i = 0; i < m; i++){
        cin>>aux;
        for(auto it : aux){
            if(!mapa[it]) resposta = false;
        }
    }
    if(resposta) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}