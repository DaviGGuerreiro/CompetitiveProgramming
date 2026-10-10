#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n;
vector<vector<int>> vec;
vector<int> valores;
vector<int> pais;
map<int, int> respostas;
vector<int> lis;

void dfs(int origem, int pai, int tamanho){
    pais[origem] = pai;
    int pos = lower_bound(lis.begin(), lis.begin() + tamanho, valores[origem]) - lis.begin();
    int antigo = lis[pos];
    lis[pos] = valores[origem];
    tamanho = max(tamanho, pos + 1);
    respostas[origem] = tamanho;
    for(auto it : vec[origem]){
        if(it != pai){
            dfs(it, origem, tamanho);
        }
    }
    lis[pos] = antigo;
}

void solve(){
    cin>>n;
    vec = vector<vector<int>> (n + 1);
    valores = vector<int> (n+1, 0);
    pais = vector<int> (n+1, 0);
    lis = vector<int> (n+1, 2e9);
    int a;
    for(int i = 2 ; i <= n; i++){
        cin>>a;
        vec[a].push_back(i);
        vec[i].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        cin>>valores[i];
    }
    dfs(1, 0, 0);
    for(int i = 2; i <= n; i++){
        cout<<respostas[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}