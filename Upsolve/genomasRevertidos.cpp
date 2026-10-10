#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n;
vector<int> origem, destino;
set<ll> vis;

ll empacota(const vector<int>& v){
    ll r = 0;
    ll mult = 1;
    for(int i = 0; i<n; i++){
        r += mult * v[i];
        mult *= 10ll;
    }
    return r;
}

int bfs(const vector<int>& v){
    queue<pair<vector<int>, int>> fila; fila.push({v, 0});
    ll pacote = empacota(v); vis.insert(pacote);
    if(v == destino) return 0;
    vector<int> x;
    while(!fila.empty()){
        const auto aux = fila.front(); fila.pop();
        for(int i = 2; i<=n; i++){
            for(int y = 0; y + i <= n; y++){
                x = aux.first;
                reverse(x.begin() + y, x.begin() + y + i);
                pacote = empacota(x);
                if(vis.find(pacote) == vis.end()){
                    vis.insert(pacote);
                    if(x == destino) return aux.second + 1;
                    fila.push({x, aux.second + 1});
                }
            }
        }
    }
    return 0;
}


void solve(){
    cin>>n;
    origem = vector<int> (n);
    destino = vector<int> (n);
    for(int i = 0; i<n; i++) origem[i] = i+1;
    for(int i = 0; i<n; i++) cin>>destino[i];
    cout<<bfs(origem)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}