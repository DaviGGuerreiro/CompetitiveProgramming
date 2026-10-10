#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll w_go;
    ll w_back;
};

vector<vector<Edge>> tree;
vector<ll> resposta;
vector<ll> tamanho;
ll val = 0, x;
int n;

void dfs(int origem, int pai){
    tamanho[origem] = 1;
    for(const auto& it : tree[origem]){
        if(it.to != pai){
            dfs(it.to, origem);
            tamanho[origem] += tamanho[it.to];
            val += (tamanho[it.to] * it.w_go);
        }
    }
}

void dfs2(int origem, int pai){  
    for(const auto& it : tree[origem]){
        if(it.to != pai){
            resposta[it.to] = resposta[origem] - (tamanho[it.to] * it.w_go) + ((n - tamanho[it.to]) * it.w_back);
            dfs2(it.to, origem);
        }
    }
}

void solve(){
    cin>>n;
    tree = vector<vector<Edge>> (n+1);
    resposta = vector<ll> (n+1, 0);
    tamanho = vector<ll> (n+1, 0);
    int a, b;
    ll c, d;
    for(int i = 0 ; i < n-1; i++){
        cin>>a>>b>>c>>d;
        tree[a].push_back({b, c, d});
        tree[b].push_back({a, d, c});
    }

    dfs(1, 0);
    resposta[1] = val;
    dfs2(1, 0);

    for(int i = 1; i <= n; i++){
        cout<<resposta[i]<<' ';
    }
    cout<<'\n';
}
//ue
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}   