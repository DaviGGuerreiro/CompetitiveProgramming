#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

int const num = 1e6 + 5;
ll n, m, p, quantidade;
vector<int> visitados;
vector<vector<int>> vec;
bool flg = false;

ll mod_mul(ll a, ll b){
    return ((a % p) * (b % p)) % p;
}


ll fexp(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b%2==1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ret;
}

void dfs(int valor){
    for(const auto it : vec[valor]){
        if(visitados[it] == 0){
            quantidade--;
            if(visitados[valor] == 1) visitados[it] = 2;
            else visitados[it] = 1;
            dfs(it);
        }
        else if(visitados[it] == visitados[valor]){
            flg = true;
        }
    }
}

void solve(){
    cin>>n>>m>>p;
    ll resposta = 0;
    quantidade = n;
    vec = vector<vector<int>> (n+1);
    visitados = vector<int> (n+1, 0);
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        if(visitados[i] == 0){
            visitados[i] = 1;
            dfs(i);
        }
    }
    if(flg){cout<<"impossible\n"; return;}

    resposta = fexp(2ll, (quantidade - 1));
    resposta = (resposta + 1ll) % p;
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}