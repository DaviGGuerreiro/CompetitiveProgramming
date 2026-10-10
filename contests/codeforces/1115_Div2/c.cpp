#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve(){
    int n, m; cin>>n>>m;
    set<int> conjunto;
    map<int,int> quantidade;
    vector<ll> vida (n);
    for(int i = 0 ; i < n ; i++){
        cin>>vida[i];
    }
    vector<vector<ll>> disturbio (n, vector<ll> (m));
    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>disturbio[i][j];
        }
    }
    ll resposta = m;
    int aux;
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j < m; j++){
            quantidade[disturbio[i][j]]++;
            conjunto.insert(disturbio[i][j]);
        }
        auto it = conjunto.end();
        ll soma = 0;
        ll peguei = 0;
        while(it != conjunto.begin()){
            it--;
            soma += (*it) * quantidade[(*it)];
            peguei += quantidade[(*it)];
            if(soma >= vida[i]){
                int dif = (soma - vida[i])/(*it);
                peguei -= dif;
                resposta = min(resposta, peguei);
                break;
            }
            if(peguei > resposta) break;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}