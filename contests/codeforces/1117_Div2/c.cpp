#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll n, m;
vector<vector<ll>> vec;
vector<bool> v;
vector<bool> visitados;
bool flg = true;
vector<int> resposta;

void dfs(int origem){
    visitados[origem] = true;
    for(auto it : vec[origem]){
        if(!visitados[it]){
            if(v[it]){
                if(flg) flg = false;
                else resposta.push_back(it);
            }
            dfs(it);
        }
    }
}

void solve(){
    cin>>n;
    vec = vector<vector<ll>> (n+1);
    v = vector<bool> (n+1, false);
    visitados = vector<bool> (n+1, false);
    int a;
    for(int i = 2; i<n+1; i++){
        cin>>a;
        vec[a].push_back(i);
    }
    cin>>m;
    for(int i = 0; i <m;i++){
        cin>>a; v[a] = true;
    }
    if(v[1]) flg = false;
    dfs(1);
    cout<<resposta.size()<<' ';
    for(int i = 0; i < resposta.size(); i++){
        cout<<resposta[i]<<' ';
    }
    resposta.clear();
    flg = true;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}