#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    map<ll, ll> mapa; int aux;
    for(int i = 0; i<n; i++){
        cin>>aux; mapa[aux]++;
    }
    ll resposta = 0;
    for(auto [key , value] : mapa){
        resposta += (ll)(((ll)(value)*(ll)(value-1))/2);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}